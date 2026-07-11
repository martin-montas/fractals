#include "line.hpp"
#include <raylib.h>

void Line::draw() {
    DrawLineV(start, end, BLUE);
}
