#ifndef H_FILE_MANIP_BASICHELPERS
#define H_FILE_MANIP_BASICHELPERS

#include "USING_BROTLI/FILE_MANIP/file-manip_export.h"

#ifdef __cplusplus

#include <cstddef>
extern "C" {

#else
#include <stddef.h>
#endif

FILE_MANIP_EXPORT void cleanupErrorMsg(const char* errorMessage);
FILE_MANIP_EXPORT size_t getFileSize(const char* filePath, const char** errorMessage);
FILE_MANIP_EXPORT void printHumanReadableSize(const size_t);

#endif

#ifdef __cplusplus
}
#endif