// This is a modified version of the ImGUI-GLFW-OpenGL3 example at
// https://github.com/ocornut/imgui/tree/master/examples/example_glfw_opengl3
// Which works both natively and with Emscripten.

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>

#define GL_SILENCE_DEPRECATION

#include <GLFW/glfw3.h>

#ifdef EMSCRIPTEN
  #include <emscripten.h>
#endif

static void glfw_error_callback(int error, const char* description)
{
  std::cerr << "GLFW Error " << error << ": " << description << '\n';
}

struct ProgramInfo
{
    GLFWwindow* window = nullptr;
};

static void mainLoop(void*);

int main(int, char**)
{
  ProgramInfo programInfo;

  // Setup window
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    return 1;

  const char* glsl_version = "#version 100";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

  // Create window with graphics context
  programInfo.window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
  if (programInfo.window == nullptr) {
    return 1;
  }

  glfwMakeContextCurrent(programInfo.window);
  glfwSwapInterval(1);  // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void) io;
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  // ImGui::StyleColorsLight();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(programInfo.window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

#ifdef EMSCRIPTEN
  emscripten_set_main_loop_arg(mainLoop, &programInfo, 0, true);
#else
  // Main loop
  while (!glfwWindowShouldClose(programInfo.window)) {
    mainLoop(&programInfo);
  }

  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(programInfo.window);
  glfwTerminate();
#endif

  return 0;
}

static void mainLoop(void* infoPtr)
{
  ProgramInfo* const programInfo = static_cast<ProgramInfo* const>(infoPtr);

  // Our state
  static bool   show_demo_window    = true;
  static bool   show_another_window = false;
  static ImVec4 clear_color         = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // Poll and handle events (inputs, window resize, etc.)
  // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
  // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite
  // your copy of the mouse data.
  // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or
  // clear/overwrite your copy of the keyboard data. Generally you may always pass all inputs to dear imgui, and hide
  // them from your application based on those two flags.
  glfwPollEvents();

  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to
  // learn more about Dear ImGui!).
  if (show_demo_window) {
    ImGui::ShowDemoWindow(&show_demo_window);
  }

  // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
  {
    static float f       = 0.0f;
    static int   counter = 0;

    ImGui::Begin("Hello, world!");  // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text.");           // Display some text (you can use a format strings too)
    ImGui::Checkbox("Demo Window", &show_demo_window);  // Edit bools storing our window open/close state
    ImGui::Checkbox("Another Window", &show_another_window);

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);              // Edit 1 float using a slider from 0.0f to 1.0f
    ImGui::ColorEdit3("clear color", (float*) &clear_color);  // Edit 3 floats representing a color

    if (ImGui::Button("Button"))  // Buttons return true when clicked (most widgets return true when edited/activated)
      counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text(
        "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
  }

  // 3. Show another simple window.
  if (show_another_window) {
    ImGui::Begin("Another Window", &show_another_window);  // Pass a pointer to our bool variable (the window will have
                                                           // a closing button that will clear the bool when clicked)
    ImGui::Text("Hello from another window!");
    if (ImGui::Button("Close Me"))
      show_another_window = false;
    ImGui::End();
  }

  // Rendering
  ImGui::Render();
  int display_w, display_h;
  glfwGetFramebufferSize(programInfo->window, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClearColor(
      clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(programInfo->window);
}