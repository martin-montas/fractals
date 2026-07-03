#include <raylib.h>
#include <raymath.h>

#define WIDTH  1000
#define HEIGHT 1000

// Rotates any point around a custom pivot position
Vector2 Vector2RotateAroundPivot(Vector2 point, Vector2 pivot, float angleRadians) {
    // Step 1: Subtract pivot to treat the pivot as (0,0)
    Vector2 relativePoint = Vector2Subtract(point, pivot);

    // Step 2: Rotate around (0,0)
    Vector2 rotatedRelative = Vector2Rotate(relativePoint, angleRadians);

    // Step 3: Add pivot back to return to screen coordinates
    return Vector2Add(pivot, rotatedRelative);
}

float rotationAngle    = 45.0f * DEG2RAD;
float shrinkPercentage = 0.70f;
void  render_line(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        return;
    }
    /* drawing left branch */
    DrawLine(x1, y1, x2, y2, BLUE);

    render_line(x1 / 2, y1 / 2, x1, y1, depth - 1);

    Vector2 lineStart = {x1 / 2, y1 / 2};
    Vector2 lineEnd   = {x1, y1};

    Vector2 up = {x1, y1 / 4};
    // finds direction
    Vector2 localDirection = Vector2Subtract(up, lineEnd);

    float distance = Vector2Distance(lineEnd, up);
    // makes it smaller
    Vector2 scaledLocal = Vector2Scale(localDirection, shrinkPercentage);

    // STEP D: Convert degrees to radians and rotate the vector
    Vector2 rotatedScaledLocal = Vector2Rotate(scaledLocal, rotationAngle);

    Vector2 finalStart = Vector2Add(lineEnd, rotatedScaledLocal);

    DrawLineV(finalStart, lineEnd, RED);
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal: Branch set");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT, BLUE);
        render_line((WIDTH / 2), (HEIGHT / 2), (WIDTH / 2), HEIGHT / 2, 3);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
