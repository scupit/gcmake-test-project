#include <string>

#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"
#include "fmt/core.h"

int main(int argc, char** argv) {
  CLI::App app("Very nice description");

  std::string name;
  app.add_option("-n,--name", name, "The given name")
    ->required();

  CLI11_PARSE(app, argc, argv);

  fmt::print("Name: {}", name);

	return EXIT_SUCCESS;
}
