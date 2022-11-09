#ifndef H_USING_ZSTD_COMMON
#define H_USING_ZSTD_COMMON

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "USING_BROTLI/file-manip.h"

typedef enum {
  ResultOk,
  ErrFileSizeGet,
  ErrBufferAllocation,
  ErrFileTooLarge,
  ErrWholeFileNotRead,
  ErrWholeFileNotWritten,
  ErrNotBrotliFile,
  ErrOriginalSizeUnknown
} ReturnCode;

typedef struct {
  size_t given;
  size_t expected;
} TwoSizes;

typedef struct {
  ReturnCode code;
  union {
    const char* errorMessage;
    void* buffer;
    TwoSizes bytesRead;
    TwoSizes bytesWritten;
  };
} CommonError;

void cleanupError(CommonError*);
void printError(const CommonError*);
char hasError(const CommonError*);
CommonError noError(void);

void printHumanReadableSizeTo(FILE*, const size_t);
void printHumanReadableSize(const size_t fileSize);

CommonError mallocAndLoadFile(
  const char* filePath,
  void** buffer,
  size_t* bufferSize
);

CommonError loadFileIntoBuffer(
  const char* filePath,
  const size_t fileSize,
  void* buffer,
  const size_t bufferSize
);

CommonError saveFile(
  const char* outFilePath,
  void* buffer,
  size_t bufferSize
);

#endif
