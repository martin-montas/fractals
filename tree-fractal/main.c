#include <raylib.h>
#include <raymath.h>

#define WIDTH  1000
#define HEIGHT 1000

Vector2 draw_rotate_blue(Vector2 start, Vector2 end, float angle, float scale) {
    Vector2 localDirection     = Vector2Subtract(start, end);
    float   distance           = Vector2Distance(end, start);
    Vector2 scaledLocal        = Vector2Scale(localDirection, scale);
    Vector2 rotatedScaledLocal = Vector2Rotate(scaledLocal, angle);

    Vector2 finalStart = Vector2Add(end, rotatedScaledLocal);
    DrawLineV(finalStart, end, BLUE);
    return finalStart;
}

float rotate_right = 45.0f * DEG2RAD;
float rotate_left  = 315.0f * DEG2RAD;
float shrink       = 0.70f;
void  render_line(int x1, int y1, int x2, int y2, int depth, float shrink) {
    if (depth == 0) {
        return;
    }
    Vector2 line_end   = {x1, y1};
    Vector2 line_start = {x2, y2};

    Vector2 start_left  = draw_rotate_blue(line_start, line_end, -40.0f, shrink);
    Vector2 start_right = draw_rotate_blue(line_start, line_end, +40.0f, shrink);

    render_line(start_left.x, start_left.y, line_end.x, line_end.y, depth - 1, shrink * 0.9f);
    render_line(start_right.x, start_right.y, line_end.x, line_end.y, depth - 1, shrink * 0.9f);
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal: Branch set");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(WIDTH / 2, HEIGHT - 200, WIDTH / 2, HEIGHT, BLUE);
        render_line(WIDTH / 2, HEIGHT - 200, WIDTH / 2, HEIGHT, 20, shrink);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
