#include "line.hpp"
#include <raylib.h>

void Line::draw() {
    DrawLineV(start, end, BLUE);
}

void Line::divide_line_half() {
    DrawLineV(start, end, BLUE);
}
