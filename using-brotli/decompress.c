// Better reference examples can be found at 
// https://github.com/facebook/zstd/blob/dev/examples

#include "USING_BROTLI/Results.h"
#include "USING_BROTLI/common.h"
#include "USING_BROTLI/file-manip.h"

#include <stdio.h>
#include <stdlib.h>

#include "brotli/decode.h"

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

  // Decompressed files will fit in up to 32MB. In real-world code, you should decompress
  // using a stream instead. This file is just an example. I'll probably update it to use a stream
  // in the future.
  const size_t maxDecodeSize = (size_t) 1024 * 1024 * 1024 * 32;
  void* const decompressedBuffer = malloc(maxDecodeSize);

  size_t actualDecodedSize = maxDecodeSize;

  BrotliDecoderResult resultCode = BrotliDecoderDecompress(
    compressedBufSize,
    compressedBuffer,
    &actualDecodedSize,
    decompressedBuffer
  );

  if (resultCode != BROTLI_DECODER_RESULT_SUCCESS) {
    fprintf(stderr, "An error occurred when decompressing the file. Since this is a test program, the max decompressed file size is ");
    printHumanReadableSizeTo(stderr, maxDecodeSize);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
  }

  CommonError writeError = saveFile(outFilePath, decompressedBuffer, actualDecodedSize);

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
      .outSize = actualDecodedSize
    }
  };
}
