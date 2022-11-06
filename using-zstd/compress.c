// Better reference examples can be found at 
// https://github.com/facebook/zstd/blob/dev/examples

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <zstd.h>

#include "USING_ZSTD/file-manip.h"

#include "USING_ZSTD/common.h"
#include "USING_ZSTD/Results.h"

#define EXTENSION ".zst"

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

  const size_t compressedBufSize = ZSTD_compressBound(fileSize);
  void* const compressedBuffer = malloc(compressedBufSize);

  const size_t compressedSize = ZSTD_compress(
    compressedBuffer,
    compressedBufSize,
    fileBuffer,
    fileSize,
    1 // Basic compression level
  );

  if (ZSTD_isError(compressedSize)) {
    fprintf(stderr, "Error when compressing file: %s", ZSTD_getErrorName(compressedSize));
    exit(EXIT_FAILURE);
  }

  CommonError saveResult = saveFile(outFilePath, compressedBuffer, compressedSize);

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
      .outSize = compressedSize
    }
  };
}
