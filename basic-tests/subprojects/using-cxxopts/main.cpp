#include <iostream>
#include <string>

#include "cxxopts.hpp"

int main(int argc, char** argv) {
  cxxopts::Options options("TheProgram", "Very cool program description");

  try {
    options.add_options()
      ("f,flag", "Some boolean flag")
      ("n,number", "An int", cxxopts::value<int>()->default_value("14"))
      ("s,str", "Some required string", cxxopts::value<std::string>());
  }
  catch (const cxxopts::OptionSpecException& optionDefinitionError) {
    std::cout << optionDefinitionError.what() << std::endl;
    exit(EXIT_FAILURE);
  }

  auto result = options.parse(argc, argv);

  if (result.count("flag")) {
    std::cout << "Flag was passed.\n";
  }

  try {
    std::cout << "Number: " << result["number"].as<int>()
      << "\nRequired string: " << result["str"].as<std::string>()
      << std::endl;
  }
  catch (const cxxopts::OptionParseException& optionParsingError) {
    std::cout << optionParsingError.what() << std::endl;
    exit(EXIT_FAILURE);
  }

	return EXIT_SUCCESS;
}
