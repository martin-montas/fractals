#ifndef SRC_LINE_HPP_
#define SRC_LINE_HPP_

#include <raylib.h>

class Line {
  public:
    Vector2 start;           /* vector start of line */
    Vector2 end;             /* vector end of line */
    void    draw();          /* draws a single line */
    void    divide_create(); /* divides the lines into other */
};

#endif // SRC_LINE_HPP_
