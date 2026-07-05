#ifndef SRC_LINE_HPP_
#define SRC_LINE_HPP_

#include <raylib.h>

class Line {
    Vector2 start; /* vector start of line */
    Vector2 end;   /* vector end of line */
  public:
    void draw();
    void divide_line_half();
};

#endif // SRC_LINE_HPP_
