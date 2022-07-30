#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

typedef struct
{
    SDL_Window* window;
    char        isClosed;
} WindowContainer;

WindowContainer wrapWindow(SDL_Window* window)
{
  return (WindowContainer){.window = window, .isClosed = 0};
}

void closeWindow(WindowContainer* winContainer)
{
  if (!winContainer->isClosed) {
    SDL_DestroyWindow(winContainer->window);
    winContainer->isClosed = 1;
  }
}

int main(int argc, char* argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    printf("SDL failed to initialize due to error: %s\n", SDL_GetError());

    return EXIT_FAILURE;
  }
  else {
    printf("SDL initialized successfully!\n");
  }

  WindowContainer winContainer = wrapWindow(SDL_CreateWindow("Noice SDL Window",
                                                             SDL_WINDOWPOS_UNDEFINED,
                                                             SDL_WINDOWPOS_UNDEFINED,
                                                             WINDOW_WIDTH,
                                                             WINDOW_HEIGHT,
                                                             SDL_WINDOW_SHOWN));

  if (winContainer.window == NULL) {
    printf("Window could not be created. Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
  else {
    printf("Window created successfully!\n");
  }

  SDL_Event event;
  char      isFinished = 0;

  // while (SDL_PollEvent(&event)) {
  while (!isFinished && SDL_WaitEvent(&event)) {
    if (event.type == SDL_WINDOWEVENT) {
      switch (event.window.event) {
        case SDL_WINDOWEVENT_CLOSE:
          printf("SDL Window Closed\n");
          closeWindow(&winContainer);
          isFinished = 1;
          break;
        case SDL_WINDOWEVENT_MOVED:
          printf("Window %d moved to %d,%d\n", event.window.windowID, event.window.data1, event.window.data2);
          break;
      }
    }
  }

  closeWindow(&winContainer);

  SDL_Quit();
  return EXIT_SUCCESS;
}
