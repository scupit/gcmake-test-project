#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

int main(int argc, char* argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    printf("SDL failed to initialize due to error: %s\n", SDL_GetError());

    return EXIT_FAILURE;
  }
  else {
    printf("SDL initialized successfully!\n");
  }

  SDL_Window* window = SDL_CreateWindow("Noice SDL Window",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        WINDOW_WIDTH,
                                        WINDOW_HEIGHT,
                                        SDL_WINDOW_SHOWN);

  if (window == NULL) {
    printf("Window could not be created. Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  const int  imageOutputFormat = STBI_rgb_alpha;
  const char imagePath[]       = "resources/example_image.jpeg";
  int        imageWidth, imageHeight, originalFormat;

  unsigned char* imageData = stbi_load(imagePath, &imageWidth, &imageHeight, &originalFormat, imageOutputFormat);

  if (imageData == NULL) {
    printf("Failed to load image from '%s'. Reason: %s\n", imagePath, stbi_failure_reason());
    return EXIT_FAILURE;
  }

  Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif

  SDL_Surface* imageSurface = SDL_CreateRGBSurfaceFrom((void*) imageData,
                                                       imageWidth,
                                                       imageHeight,
                                                       32,              // 4 bytes per pixel
                                                       4 * imageWidth,  // 4 bytes per pixel * pixels per row
                                                       rmask,
                                                       gmask,
                                                       bmask,
                                                       amask);

  if (imageSurface == NULL) {
    printf("Failed to create surface. Reason: %s", SDL_GetError());
    stbi_image_free(imageData);
    return EXIT_FAILURE;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Texture*  texture  = SDL_CreateTextureFromSurface(renderer, imageSurface);

  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  SDL_Event event;
  char      isFinished = 0;

  // while (SDL_PollEvent(&event)) {
  while (!isFinished && SDL_WaitEvent(&event)) {
    if (event.type == SDL_WINDOWEVENT) {
      switch (event.window.event) {
        case SDL_WINDOWEVENT_CLOSE:
          printf("Window close event received.\n");
          isFinished = 1;
          break;
        case SDL_WINDOWEVENT_MOVED:
          printf("Window %d moved to %d,%d\n", event.window.windowID, event.window.data1, event.window.data2);
          break;
      }
    }
  }

  SDL_FreeSurface(imageSurface);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  stbi_image_free(imageData);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
