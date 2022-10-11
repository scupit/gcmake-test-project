#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {
  spdlog::info("Alright, this is cool.");
  spdlog::warn("This is a warning");
  spdlog::error("{:<30}", "This is an error message");

  auto err_console = spdlog::stdout_color_mt("error_logger");
  
  // This is cool, apparently you can get logger sinks globally or reference them directly.
  spdlog::get("error_logger")->warn("This is a colored warning");
  err_console->error("Oh no: {}", 12);
  
	return EXIT_SUCCESS;
}
