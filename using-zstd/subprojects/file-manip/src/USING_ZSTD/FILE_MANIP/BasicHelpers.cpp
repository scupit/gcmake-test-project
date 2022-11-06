#include "USING_ZSTD/FILE_MANIP/BasicHelpers.h"

#include <cstring>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

extern "C" {
  void cleanupErrorMsg(const char* errorMessage) {
    delete[] errorMessage;
  }

  size_t getFileSize(const char* filePath, const char** errorMessage) {
    std::error_code ec;
    std::uintmax_t fileSize = fs::file_size(filePath, ec);

    if (ec) {
      std::string message = ec.message(); 
      const auto messageCSize = message.size() + 1;
      char* newErrMsg = new char[messageCSize];
      std::memcpy(newErrMsg, message.c_str(), messageCSize * sizeof(char));
      *errorMessage = newErrMsg;
      return 0;
    }
    else {
      *errorMessage = NULL;
      return static_cast<size_t>(fileSize);
    }
  }
}