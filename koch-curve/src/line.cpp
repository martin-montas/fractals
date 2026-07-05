#include "line.hpp"
#include <raylib.h>

void Line::draw() {
    DrawLineV(start, end, BLUE);
}

void Line::divide_create() {}
