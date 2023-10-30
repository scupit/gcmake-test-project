// This is a modified version of the raylib web example file at
// https://github.com/raysan5/raylib/blob/master/examples/core/core_basic_window_web.c
#include <stdlib.h>
#include "raylib.h"

#ifdef EMSCRIPTEN
  #include <emscripten/emscripten.h>
#endif

void updateAndDrawFrame(void);

// This is raylib's basic example.
// https://github.com/raysan5/raylib#basic-example
int main(void) {
  InitWindow(800, 450, "Basic raylib window example");

  // This explains why the main while loop should be avoided when building for web.
  // https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)#4-setup-raylib-game-for-web
  #ifdef EMSCRIPTEN
    emscripten_set_main_loop(updateAndDrawFrame, 0, 1);
  #else
    while (!WindowShouldClose()) {
      updateAndDrawFrame();
    }
  #endif

  CloseWindow();
	return EXIT_SUCCESS;
}

void updateAndDrawFrame(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawText("Some very cool text", 190, 200, 20, LIGHTGRAY);
  EndDrawing();
}
