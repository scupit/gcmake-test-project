#include "USING_ZSTD/common.h"

#include <stdio.h>

void printError(const CommonError* result) {
  if (hasError(result)) {
    fprintf(stderr, "Error: ");
  }

  switch (result->code) {
    case ResultOk:
      fprintf(stderr, "Result is fine. No errors occurred.");
      break;
    case ErrFileTooLarge:
      fprintf(
        stderr,
        "Loaded file (%llu) is larger than the allocated buffer (%llu)",
        result->bytesRead.given,
        result->bytesRead.expected
      );
      break;
    case ErrWholeFileNotRead:
      fprintf(
        stderr,
        "Only %llu bytes of %llu were read successfully.",
        result->bytesRead.given,
        result->bytesRead.expected
      );
      break;
    case ErrWholeFileNotWritten:
      fprintf(
        stderr,
        "Only %llu bytes of %llu were written successfully.",
        result->bytesWritten.given,
        result->bytesWritten.expected
      );
      break;
    case ErrFileSizeGet:
      fprintf(
        stderr,
        "Failed to retrieve file size. %s",
        result->errorMessage
      );
      break;
    case ErrBufferAllocation:
      fprintf(stderr, "Failed to allocate data buffer.");
      break;
    case ErrOriginalSizeUnknown:
      fprintf(stderr, "Unable to determine original file size.");
      break;
    case ErrNotZstdFile:
      fprintf(stderr, "The file cannot be read because it wasn't compressed by zstd.");
      break;
  }

  fprintf(stderr, "\n");
}

void cleanupError(CommonError* result) {
  switch (result->code) {
    case ResultOk: break;
    case ErrFileTooLarge: break;
    case ErrWholeFileNotRead: break;
    case ErrWholeFileNotWritten: break;
    case ErrOriginalSizeUnknown: break;
    case ErrNotZstdFile: break;
    case ErrFileSizeGet:
      cleanupErrorMsg(result->errorMessage);
      break;
    case ErrBufferAllocation:
      free(result->buffer);
      break;
  }
}

char hasError(const CommonError* result) {
  return result->code != ResultOk;
}

CommonError noError(void) {
  return (CommonError) {
    .code = ResultOk
  };
}

void printHumanReadableSize(const size_t fileSize) {
  // I think it's interesting that the const is required here.
  static const char* sizeNames[] = {
    "B",
    "KB",
    "MB",
    "GB",
    "TB"
  };

  double fileSizeDecimal = (double) fileSize;
  int i = 0;

  while (fileSizeDecimal > 1024) {
    fileSizeDecimal /= 1024;
    ++i;
  }

  printf("%.1f%s", fileSizeDecimal, sizeNames[i]);
}

CommonError loadFileIntoBuffer(
  const char* filePath,
  const size_t fileSize,
  void* buffer,
  const size_t bufferSize
) {
  if (fileSize > bufferSize) {
    return (CommonError) {
      .code = ErrFileTooLarge,
      .bytesRead = (TwoSizes) {
        .given = fileSize,
        .expected = bufferSize
      }
    };
  }

  FILE* inFile = fopen(filePath, "rb");
  const size_t readSize = fread(buffer, 1, fileSize, inFile);

  if (readSize != fileSize) {
    return (CommonError) {
      .code = ErrWholeFileNotRead,
      .bytesRead = (TwoSizes) {
        .given = readSize,
        .expected = fileSize
      }
    };
  }

  return noError();
}

CommonError mallocAndLoadFile(
  const char* filePath,
  void** buffer,
  size_t* bufferSize
) {
  const char* errorMessage;
  const size_t fileSize = getFileSize(filePath, &errorMessage);
  
  if (errorMessage) {
    return (CommonError) {
      .code = ErrFileSizeGet,
      .errorMessage = errorMessage
    };
  }

  *bufferSize = fileSize;
  *buffer = malloc(fileSize);

  if (!buffer) {
    return (CommonError) {
      .code = ErrBufferAllocation,
      .buffer = *buffer
    };
  }

  const CommonError result = loadFileIntoBuffer(filePath, fileSize, *buffer, *bufferSize);

  if (hasError(&result)) {
    return result;
  }

  return noError();
}

CommonError saveFile(
  const char* outFilePath,
  void* buffer,
  size_t bufferSize
) {
  FILE* const outFile = fopen(outFilePath, "wb");
  const size_t writtenSize = fwrite(buffer, 1, bufferSize, outFile);

  if (writtenSize != bufferSize) {
    fclose(outFile);
    return (CommonError) {
      .code = ErrWholeFileNotWritten,
      .bytesWritten = (TwoSizes) {
        .given = writtenSize,
        .expected = bufferSize
      }
    };
  }

  fclose(outFile);
  return noError();
}
