#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "src/line.hpp"

#define WIDTH  1000
#define HEIGHT 1000

using namespace std {
    std::vector<Line> line_vector;
}

void generate(int depth) {
    if (depth == 0) {
        return;
    }
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal: Koch curve");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        generate(1, );
    }

    CloseWindow();
    return 0;
}
