// Better reference examples can be found at 
// https://github.com/facebook/zstd/blob/dev/examples

#include "USING_BROTLI/file-manip.h"
#include "USING_BROTLI/common.h"
#include "USING_BROTLI/Results.h"

#include "brotli/encode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXTENSION ".br"

CompressionResult compress(const char* inFilePath, const char* outFilePath);

int main(int argc, const char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Must provide a single argument, which is a path to an uncompressed file.");
    exit(EXIT_FAILURE);
  }

  const char* const inFilePath = argv[1];
  const size_t inFileNameLength = strlen(inFilePath);

  char outFilePath[inFileNameLength + sizeof(EXTENSION) + 1];
  memcpy((void*) outFilePath, inFilePath, inFileNameLength * sizeof(char));
  memcpy(&outFilePath[inFileNameLength], EXTENSION, sizeof(EXTENSION));

  CompressionResult result = compress(inFilePath, outFilePath);

  if (result.wasSuccess) {
    printf("Initial: ");
    printHumanReadableSize(result.sizes.inSize);
    printf("\nCompressed: ");
    printHumanReadableSize(result.sizes.outSize);
  }
  else {
    printError(&result.error);
    cleanupError(&result.error);
  }

	return EXIT_SUCCESS;
}

CompressionResult compress(const char*const inFilePath, const char* const outFilePath) {
  size_t fileSize;
  void* fileBuffer;
  CommonError loadResult = mallocAndLoadFile(inFilePath, &fileBuffer, &fileSize);

  if (hasError(&loadResult)) {
    return (CompressionResult) {
      .wasSuccess = 0,
      .error = loadResult
    };
  }

  const size_t compressedBufSize = BrotliEncoderMaxCompressedSize(fileSize);
  void* const compressedBuffer = malloc(compressedBufSize);

  size_t compressedDataSize = compressedBufSize;

  const BROTLI_BOOL didCompressionSucceed = BrotliEncoderCompress(
    BROTLI_DEFAULT_QUALITY,
    BROTLI_DEFAULT_WINDOW,
    BROTLI_DEFAULT_MODE,
    fileSize,
    fileBuffer,
    &compressedDataSize,
    compressedBuffer
  );

  if (!didCompressionSucceed) {
    fprintf(stderr, "Error when compressing file: Compression failed. The output buffer may have been too small." );
    exit(EXIT_FAILURE);
  }

  CommonError saveResult = saveFile(outFilePath, compressedBuffer, compressedDataSize);

  if (hasError(&saveResult)) {
    return (CompressionResult) {
      .wasSuccess = 0,
      .error = saveResult
    };
  }
  
  free(fileBuffer);
  free(compressedBuffer);

  return (CompressionResult) {
    .wasSuccess = 1,
    .sizes = {
      .inSize = fileSize,
      .outSize = compressedDataSize
    }
  };
}
