#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "src/generator.hpp"
#include "src/line.hpp"

#define WIDTH 1000
#define HEIGHT 1000

int main() {
  InitWindow(WIDTH, HEIGHT, "Fractal: L System");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
