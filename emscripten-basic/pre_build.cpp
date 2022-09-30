#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#ifdef EMSCRIPTEN
  #include <emscripten.h>
#endif

int main() {
  #ifdef EMSCRIPTEN
    EM_ASM(
      FS.mkdir("my-root");
      FS.mount(NODEFS, { root: "." }, "my-root");
    );
  #endif

  const std::string resourcesDir =
    #ifdef EMSCRIPTEN
      "my-root/resources";
    #else
      "resources";
    #endif

  if (!std::filesystem::is_directory(resourcesDir)) {
    std::filesystem::create_directory(resourcesDir);
  }

  std::ofstream fileOut(resourcesDir + "/cool-file.txt");
  fileOut << "Aw yeah, this text is in a file." << std::endl;

  std::cout << std::endl;

  return EXIT_SUCCESS;
}