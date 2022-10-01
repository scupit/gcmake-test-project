// Dear ImGui: standalone example application for Emscripten, using SDL2 + OpenGL3
// (Emscripten is a C++-to-javascript compiler, used to publish executables for the web. See https://emscripten.org/)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

// This is mostly the same code as the SDL2 + OpenGL3 example, simply with the modifications needed to run on
// Emscripten. It is possible to combine both code into a single source file that will compile properly on Desktop and
// using Emscripten. See https://github.com/ocornut/imgui/pull/2492 as an example on how to do just that.

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl.h"
#include <iostream>

#include <SDL.h>

#ifdef EMSCRIPTEN
  #include <SDL_opengles2.h>
  #include <emscripten.h>
#else
  #include <SDL_opengl.h>
#endif

struct ProgramInfo
{
    SDL_Window*   window     = nullptr;
    SDL_GLContext glContext  = nullptr;
    bool          shouldExit = false;
};

// For clarity, our main loop code is declared at the end.
static void main_loop(void*);

int main(int, char**)
{
  ProgramInfo programInfo;

  // Setup SDL
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
    std::cerr << "Error: " << SDL_GetError() << '\n';
    return -1;
  }

  // For the browser using Emscripten, we are going to use WebGL1 with GL ES2. See the Makefile. for requirement
  // details. It is very likely the generated file won't work in many browsers. Firefox is the only sure bet, but I have
  // successfully run this code on Chrome for Android for example.
  const char* glsl_version = "#version 100";
  // const char* glsl_version = "#version 300 es";
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

  // Create window with graphics context
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
  SDL_DisplayMode current;
  SDL_GetCurrentDisplayMode(0, &current);
  SDL_WindowFlags window_flags =
      (SDL_WindowFlags) (SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

  programInfo.window = SDL_CreateWindow(
      "Dear ImGui Emscripten example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);

  programInfo.glContext = SDL_GL_CreateContext(programInfo.window);

  if (!programInfo.glContext) {
    std::cerr << "Failed to initialize WebGL context!\n";
    return 1;
  }
  SDL_GL_SetSwapInterval(1);  // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void) io;
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

#ifdef EMSCRIPTEN
  // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini
  // file. You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
  io.IniFilename = NULL;
#endif

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  // ImGui::StyleColorsLight();

  // Setup Platform/Renderer backends
  ImGui_ImplSDL2_InitForOpenGL(programInfo.window, programInfo.glContext);
  ImGui_ImplOpenGL3_Init(glsl_version);

#ifdef EMSCRIPTEN
  // This function call won't return, and will engage in an infinite loop, processing events from the browser, and
  // dispatching them.
  emscripten_set_main_loop_arg(main_loop, &programInfo, 0, true);
#else
  while (!programInfo.shouldExit) {
    main_loop(&programInfo);
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_GL_DeleteContext(programInfo.glContext);
  SDL_DestroyWindow(programInfo.window);
  SDL_Quit(); 
  return EXIT_SUCCESS;
#endif
}

static void main_loop(void* infoPtr)
{
  ProgramInfo* const programInfo = static_cast<ProgramInfo* const>(infoPtr);

  ImGuiIO& io = ImGui::GetIO();

  // Our state (make them static = more or less global) as a convenience to keep the example terse.
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
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    ImGui_ImplSDL2_ProcessEvent(&event);
    // Capture events here, based on io.WantCaptureMouse and io.WantCaptureKeyboard

#ifndef EMSCRIPTEN
    if (event.type == SDL_QUIT) {
      programInfo->shouldExit = true;
    }
    else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
             && event.window.windowID == SDL_GetWindowID(programInfo->window))
    {
      programInfo->shouldExit = true;
    }
#endif
  }

  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();

  // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to
  // learn more about Dear ImGui!).
  if (show_demo_window)
    ImGui::ShowDemoWindow(&show_demo_window);

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
  SDL_GL_MakeCurrent(programInfo->window, programInfo->glContext);
  glViewport(0, 0, static_cast<int>(io.DisplaySize.x), static_cast<int>(io.DisplaySize.y));
  glClearColor(
      clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  SDL_GL_SwapWindow(programInfo->window);
}
