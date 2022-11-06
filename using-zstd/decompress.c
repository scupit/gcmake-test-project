// Better reference examples can be found at 
// https://github.com/facebook/zstd/blob/dev/examples

#include "USING_ZSTD/Results.h"
#include "USING_ZSTD/common.h"
#include "USING_ZSTD/file-manip.h"
#include <stdio.h>
#include <stdlib.h>

#include <zstd.h>

DecompressionResult decompress(const char* inFilePath, const char* outFilePath);

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Incorrect arguments. Must provide a single IN file name and a single OUT file name.");
    exit(EXIT_FAILURE);
  }

  CompressionResult result = decompress(argv[1], argv[2]);

  if (result.wasSuccess) {
    printf("Initial: ");
    printHumanReadableSize(result.sizes.inSize);
    printf("\nDecompressed: ");
    printHumanReadableSize(result.sizes.outSize);
  }
  else {
    printError(&result.error);
    cleanupError(&result.error);
  }

	return EXIT_SUCCESS;
}

DecompressionResult decompress(const char* inFilePath, const char* outFilePath) {
  void* compressedBuffer;
  size_t compressedBufSize;
  CommonError loadResult = mallocAndLoadFile(inFilePath, &compressedBuffer, &compressedBufSize);

  if (hasError(&loadResult)) {
    return (DecompressionResult) {
      .wasSuccess = 0,
      .error = loadResult
    };
  }

  const unsigned long long decompressedSize = ZSTD_getFrameContentSize(compressedBuffer, compressedBufSize);

  if (decompressedSize == ZSTD_CONTENTSIZE_ERROR) {
    return (DecompressionResult) {
      .wasSuccess = 0,
      .error = {
        .code = ErrNotZstdFile
      }
    };
  }
  else if (decompressedSize == ZSTD_CONTENTSIZE_UNKNOWN) {
    return (DecompressionResult) {
      .wasSuccess = 0,
      .error = {
        .code = ErrOriginalSizeUnknown
      }
    };
  }

  void* const decompressedBuffer = malloc((size_t) decompressedSize);
  const size_t decompressionResultCode = ZSTD_decompress(
    decompressedBuffer,
    decompressedSize,
    compressedBuffer,
    compressedBufSize
  );

  if (ZSTD_isError(decompressionResultCode)) {
    fprintf(stderr, "Error when decompressing file: %s", ZSTD_getErrorName(decompressionResultCode));
    exit(EXIT_FAILURE);
  }

  CommonError writeError = saveFile(outFilePath, decompressedBuffer, decompressedSize);

  if (hasError(&writeError)) {
    return (DecompressionResult) {
      .wasSuccess = 0,
      .error = writeError
    };
  }

  free(compressedBuffer);
  free(decompressedBuffer);

  return (DecompressionResult) {
    .wasSuccess = 1,
    .sizes = {
      .inSize = compressedBufSize,
      .outSize = decompressedSize
    }
  };
}