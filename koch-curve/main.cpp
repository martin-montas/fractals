#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "src/line.hpp"
#include "src/generator.hpp"

#define WIDTH  1000
#define HEIGHT 1000

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal: Koch curve");
    SetTargetFPS(60);
    Vector2    lineStart = {50, HEIGHT / 2};
    Vector2    lineEnd   = {600, HEIGHT / 2};
    Generator* gen       = new Generator();

    Line init;
    init.start = lineStart;
    init.end   = lineEnd;
    std::vector<Line> vect;
    vect.push_back(init);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        gen->generate_lines(5, vect);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
