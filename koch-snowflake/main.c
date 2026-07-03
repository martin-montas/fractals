#include <raylib.h>
#include <math.h>

#define WIDTH  600
#define HEIGHT 800

Vector2 RotatePoint(Vector2 p, Vector2 center, float angle) {
    float s = sinf(angle);
    float c = cosf(angle);

    // translate point to origin
    float x = p.x - center.x;
    float y = p.y - center.y;

    // rotate
    float xr = x * c - y * s;
    float yr = x * s + y * c;

    // translate back
    return (Vector2){xr + center.x, yr + center.y};
}

void render_line(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 30) {
        return;
    }
    // left stick
    DrawLine(x1, y1, x2, y2, BLUE);

    // write stick
    DrawLine(x2 * 2, y1, x2, y2, BLUE);

    render_line(x1 / 2, y1 / 2, x1, y1, depth + 1);
}
int main() {
    InitWindow(WIDTH, HEIGHT, "fractal: branch set");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        render_line((WIDTH / 2), (HEIGHT / 2), (WIDTH / 2), HEIGHT, 0);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
