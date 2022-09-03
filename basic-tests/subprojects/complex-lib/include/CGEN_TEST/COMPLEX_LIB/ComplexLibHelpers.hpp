#ifndef HPP_COMPLEX_LIB_COMPLEXLIBHELPERS
#define HPP_COMPLEX_LIB_COMPLEXLIBHELPERS

#include <iostream>

#include "CGEN_TEST/COMPLEX_LIB/complex-lib_export.h"

#include "GLFW/glfw3.h"
#include "glm/mat4x4.hpp"
#include "nlohmann/json.hpp"

struct COMPLEX_LIB_EXPORT Dimensions
{
    int x;
    int y;
};

COMPLEX_LIB_EXPORT Dimensions getMonitorDimensions(GLFWmonitor*);

COMPLEX_LIB_EXPORT void printMatrix(const glm::mat4);
COMPLEX_LIB_EXPORT int  showExampleImage(const char* imagePath);

template <typename T>
void printJsonAndOtherThing(const nlohmann::json& json, const T& otherThing)
{
  std::cout << "JSON: " << json << "\n"
            << "Other thing: " << otherThing << "\n";
}

template <typename T>
T doubledItem(const T& item) {
  return item * 2;
}

#endif
