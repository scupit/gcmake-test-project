#include <stdlib.h>
#include "raylib.h"

// This is raylib's basic example.
// https://github.com/raysan5/raylib#basic-example
int main(void) {
  InitWindow(800, 450, "Basic raylib window example");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Some very cool text", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
	return EXIT_SUCCESS;
}
