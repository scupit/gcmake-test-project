#include<optional>
#include "fmt/core.h"
#include "argparse/argparse.hpp"

int main(int argc, char** argv) {
  argparse::ArgumentParser program("Testing argparse");

  program.add_argument("--required")
    .help("This must be passed")
    .required()
    .implicit_value(true);

  program.add_argument("--num")
    .help("Double the given integer")
    .scan<'i', int>();

  try {
    program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
    fmt::print(stderr, "{}\n{}", err.what(), program.help().str());
    return EXIT_FAILURE;
  }

  fmt::print("Args parsed successfully");

  if (const std::optional<int> maybe_num = program.present<int>("--num")) {
    const int num = maybe_num.value();
    fmt::print("Num was defined as {}. Doubled = {}", num, num * 2);
  }
  else {
    fmt::print("Num was not defined.");
  }

	return EXIT_SUCCESS;
}
