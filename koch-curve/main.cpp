#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "src/line.hpp"
#include "src/generator.hpp"

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
    Vector2    lineEnd   = {300.0f, 400.0f};
    Vector2    lineStart = {150.0f, 400.0f};
    Generator* gen       = new Generator();

    Line init;
    init.start = lineStart;
    init.end   = lineEnd;
    gen->lines.push_back(init);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
