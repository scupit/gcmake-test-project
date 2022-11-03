#include <string>
#include <vector>

#include "re2/re2.h"

#include "fmt/core.h"
#include "fmt/color.h"

int main(int argc, char** argv) {
  const std::vector<std::string> stringList = {
    "12345",
    "Something",
    "123Another",
    "Some123"
  };

  const std::string regexString = "(^.*)(123)(.*$)";
  RE2 preCompRegex(regexString);

  fmt::print("\"{}\" matches:\n\n", regexString);

  for (const std::string& str : stringList) {
    std::string beforeMatch, matchedPart, afterMatch;
    bool wasMatched = RE2::PartialMatch(str, preCompRegex, &beforeMatch, &matchedPart, &afterMatch);

    if (wasMatched) {
      fmt::print("{}", beforeMatch);
      fmt::print(
        fmt::bg(fmt::color::red),
        "{}",
        matchedPart
      );
      fmt::print("{}\n", afterMatch);
    }
  }

	return EXIT_SUCCESS;
}
