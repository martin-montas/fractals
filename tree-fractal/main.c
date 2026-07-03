#include <raylib.h>
#include <raymath.h>

#define WIDTH  1000
#define HEIGHT 1000

float angle = 45.0f * DEG2RAD;

void render_line(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        return;
    }
    /* drawing left branch */
    DrawLine(x1 / 2, y1 / 2, x1, y1, BLUE);

    /* drawing right branch */
    DrawLine(x1 * 2, y1 / 2, x1, y1, BLUE);

    /* recursion */
    render_line(x1 / 2, y1 / 2, x1 / 2, y1 / 2, depth - 1);
    // ============================================================
    /* drawing left branch */
    DrawLine((x1 * 2) - 100, (y1 / 2) / 2, x1 * 2, y1 / 2, BLUE);
    /* drawing right branch */
    DrawLine(x1 * 2, y1 / 2, x1, y1, BLUE);
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal: Branch Set");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT, BLUE);
        render_line((WIDTH / 2), (HEIGHT / 2), (WIDTH / 2), HEIGHT / 2, 2);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
