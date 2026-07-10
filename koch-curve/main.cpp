#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "src/line.hpp"

#define WIDTH  1000
#define HEIGHT 1000

void generate(int depth, std::vector<Line> line_vector) {
    if (depth == 0) {
        return;
    }
}
int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal: Koch curve");
    SetTargetFPS(60);
    Vector2 lineEnd   = {300.0f, 400.0f};
    Vector2 lineStart = {150.0f, 400.0f};
    // line0             = new Line();
    // line0.start       = lineStart;
    // line0.end         = lineEnd;

    // line_vector.push_back(line0);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
