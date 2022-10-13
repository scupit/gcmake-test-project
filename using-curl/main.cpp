#include <string>
#include "fmt/core.h"
#include "curl/curl.h"

size_t writerCallback(
  void* contents,
  size_t size,
  size_t nmemb,
  std::string* str
) {
  const size_t realSize = size * nmemb;

  try {
    str->append(static_cast<char*>(contents), realSize);
  }
  catch(const std::bad_alloc& err) {
    return EXIT_FAILURE;
  }

  return realSize;
}

int main() {
  curl_global_init(CURL_GLOBAL_DEFAULT);
  CURL* curl = curl_easy_init();

  if (curl) {
    std::string responseData;

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writerCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

    CURLcode returnCode = curl_easy_perform(curl);

    if (returnCode != CURLE_OK) {
      fmt::print(stderr, "Request failed: {}\n", curl_easy_strerror(returnCode));
    }
    else {
      fmt::print("Response: {}", responseData);
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

	return EXIT_SUCCESS;
}
