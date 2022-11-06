#ifndef H_USING_ZSTD_RESULTS
#define H_USING_ZSTD_RESULTS

#include "USING_ZSTD/file-manip.h"
#include "USING_ZSTD/common.h"

typedef struct {
  size_t inSize;
  size_t outSize;
} CompressedDifference;

typedef struct {
  char wasSuccess;
  union {
    CommonError error;
    CompressedDifference sizes;
  };
} CompressionResult;

typedef CompressionResult DecompressionResult;

#endif
