#ifndef HPP_COMPLEX_LIB_COMPLEXLIBHELPERS
#define HPP_COMPLEX_LIB_COMPLEXLIBHELPERS

#include <iostream>

#include "GLFW/glfw3.h"
#include "glm/mat4x4.hpp"
#include "nlohmann/json.hpp"

struct Dimensions
{
    int x;
    int y;
};

Dimensions getMonitorDimensions(GLFWmonitor*);

void printMatrix(const glm::mat4);
int  showExampleImage(const char* imagePath);

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
