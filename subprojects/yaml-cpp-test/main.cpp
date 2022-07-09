#include <filesystem>
#include <iostream>
#include <string>

#include "yaml-cpp/yaml.h"

std::string posixPathStr(const std::filesystem::path& thePath)
{
  std::string pathString = thePath.string();
  pathString.replace(pathString.begin(), pathString.end(), "\\", "/");
  return pathString;
}

int main(int _argc, const char** argv)
{
  const std::string relativePath = "resources/my_cool_yaml_file.yaml";

  try {
    YAML::Node theYaml  = YAML::LoadFile(relativePath);
    theYaml["AddedKey"] = "Added by the program -> " CONSTANT_FOR_FUN;
    std::cout << theYaml;
  }
  catch (YAML::BadFile badFileError) {
    auto absPath = std::filesystem::current_path();
    absPath.append(relativePath);

    std::cout << "Reading the yaml file at '" << relativePath << "' (absolute path: '" << posixPathStr(absPath)
              << "') failed with error:\n"
              << badFileError.msg << "\n\nTry running " << argv[0]
              << " from the subproject's root directory or from the build directory if you aren't already.";
  }
  return EXIT_SUCCESS;
}
