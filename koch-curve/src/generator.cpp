#include "generator.hpp"
#include "line.hpp"
#include <cstddef>

void Generator::divide_line(Line line, std::vector<Line>& vec) {
    Vector2 middle = Vector2Scale(Vector2Add(line.start, line.end), 0.5f);

    // finds the direction with the whole length
    Vector2 side = Vector2Subtract(line.end, line.start);

    // creates a perpendicular vector (with a 90 degree angle)
    Vector2 perp = {side.y, -side.x};

    // makes per a uni-vector
    perp = Vector2Normalize(perp);

    // make the legnth  half
    float   height = Vector2Length(side) * 0.3f;
    Vector2 peak   = Vector2Add(middle, Vector2Scale(perp, height));

    // first half
    Vector2 start0 = line.start;
    Vector2 end0   = Vector2Lerp(line.start, line.end, 1.0f / 3.0f);

    // second half
    Vector2 start1 = Vector2Lerp(line.start, line.end, 2.0f / 3.0f);
    Vector2 end1   = line.end;

    float   len         = Vector2Distance(line.start, line.end);
    Vector2 base_vector = {len / 2, 0.0f};

    // last half
    // Vector2 end3 = Vector2Add(lineStart, rotatedVec);
    Vector2 start3 = end0;
    Vector2 end3   = peak;

    // right side of the peak
    Vector2 start2 = peak;
    Vector2 end2   = start1;

    Line l0;
    Line l1;
    Line l2;
    Line l3;

    l0.start = start0;
    l0.end   = end0;

    l1.start = start1;
    l1.end   = end1;

    l2.start = start2;
    l2.end   = end2;

    l3.start = start3;
    l3.end   = end3;

    vec.push_back(l0);
    vec.push_back(l1);
    vec.push_back(l2);
    vec.push_back(l3);
}

void Generator::generate_lines(int depth, std::vector<Line> old_lines) {
    std::vector<Line> new_vect;
    if (depth == 0) {
        for (auto line : old_lines) {
            line.draw();
        }
        return;
    }

    if (depth != 0) {
        for (auto l : old_lines) {
            divide_line(l, new_vect);
        }
    }
    generate_lines(depth - 1, new_vect);
}
