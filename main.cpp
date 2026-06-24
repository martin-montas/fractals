#include <SDL2/SDL.h>
#include <complex>
#include <stdint.h>
#include <stdio.h>

int WIDTH = 800;
int HEIGHT = 600;

uint32_t buffer[800 * 600];

double map_pixel(int number, int map_pixel, int new_min, int new_max) {
  return new_min + ((new_max - new_min) * number) / map_pixel;
}

int main() {
  bool display_running = true;
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL Error: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_Window *window = SDL_CreateWindow(
      "Game Boy: (DMG)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      WIDTH * 2, HEIGHT * 2, SDL_WINDOW_SHOWN);

  SDL_StopTextInput();
  if (!window) {
    printf("Window Error: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

  if (!renderer) {
    printf("Renderer Error: %s\n", SDL_GetError());
    exit(1);
  }

  SDL_Texture *texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                        SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

  bool quit = false;

  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        quit = false;
        break;

      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          quit = false;
        }
        break;
      }
    }

    /* main render logic */
    for (int i = 0; i < WIDTH; i++) {
      for (int j = 0; j < HEIGHT; j++) {
        /* TODO: use this to see if a value diviates from the origin
         * (Geometry tip: You use the Pythagorean theorem here. If your complex
         * number is x+yi, the distance squared is x2+y2. If that value is
         * greater than 4, your distance is greater than 2).
         */

        // For each pixel:
        //
        // Convert the pixel into a complex number:
        // z= x + yi
        // Repeatedly calculate:
        // z=z^ 2 +c
        // After each iteration check:
        // x^2 +y^2
        //
        // If: x^2 +y^2 >4
        //
        // then it escaped → that pixel is not in the Julia set.

        // ```cpp
        // float map_pixel(int number, int map_pixel, int new_min, int new_max)
        // ```
        double y = map_pixel(i, WIDTH, -2, 2);
        double x = map_pixel(j, HEIGHT, -2, 2);

        for (int o = 0; o < 100; o++) {

          if ((x ^ 2 + y ^ 2) > 4) {
            if (o <= 20)
              buffer[(WIDTH * i) + j] = 0x0000FFFF;
            else if (o <= 80)
              buffer[(WIDTH * i) + j] = 0x66CCFFFF;
            else if (o <= 100)
              buffer[(WIDTH * i) + j] = 0x00000000;
          }
        }
      }
    }
    SDL_UpdateTexture(texture, nullptr, buffer, WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
