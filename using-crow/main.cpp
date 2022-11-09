#include <cstdlib>
#include "crow.h"

int main() {
  crow::SimpleApp app;
  CROW_ROUTE(app, "/")([]{
    return "Hello World!";
  });

  app.port(8080).multithreaded().run();
	return EXIT_SUCCESS;
}
