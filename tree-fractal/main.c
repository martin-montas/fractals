#include <raylib.h>
#include <raymath.h>

#define WIDTH  1000
#define HEIGHT 1000

Vector2 draw_rotate_red(Vector2 start, Vector2 end, float angle) {
    // finds direction
    Vector2 localDirection = Vector2Subtract(start, end);

    float distance = Vector2Distance(end, start);
    // makes it smaller
    Vector2 scaledLocal = Vector2Scale(localDirection, 0.8f);

    // STEP D: Convert degrees to radians and rotate the vector
    Vector2 rotatedScaledLocal = Vector2Rotate(scaledLocal, angle);

    Vector2 finalStart = Vector2Add(end, rotatedScaledLocal);

    DrawLineV(finalStart, end, RED);
    return finalStart;
}

Vector2 draw_rotate_blue(Vector2 start, Vector2 end, float angle) {
    // finds direction
    Vector2 localDirection = Vector2Subtract(start, end);

    float distance = Vector2Distance(end, start);
    // makes it smaller
    Vector2 scaledLocal = Vector2Scale(localDirection, 0.8f);

    // STEP D: Convert degrees to radians and rotate the vector
    Vector2 rotatedScaledLocal = Vector2Rotate(scaledLocal, angle);

    Vector2 finalStart = Vector2Add(end, rotatedScaledLocal);

    DrawLineV(finalStart, end, BLUE);
    return finalStart;
}
float rotate_right     = 45.0f * DEG2RAD;
float rotate_left      = 315.0f * DEG2RAD;
float shrinkPercentage = 0.70f;

void render_line(int x1, int y1, int depth) {
    if (depth == 0) {
        return;
    }
    Vector2 line_end   = {x1, y1};
    Vector2 line_start = {x1, y1 / 2};

    // void draw_rotate_blue(Vector2 start, end, float angle, float shrink);
    Vector2 left  = draw_rotate_blue(line_start, line_end, rotate_left);
    Vector2 right = draw_rotate_red(line_start, line_end, rotate_right);

    render_line(left.x, left.y, depth - 1);
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal: Branch set");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT, BLUE);
        render_line(WIDTH / 2, HEIGHT / 2, 3);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
