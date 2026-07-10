#ifndef GENERATOR_HPP_
#define GENERATOR_HPP_
#include <vector>
#include "line.hpp"
#include <raylib.h>
#include <raymath.h>

class Generator {
  public:
    void divide_line(Line line, std::vector<Line>& vec);
    void generate_lines(int depth, std::vector<Line> old_lines);
};
#endif // GENERATOR_HPP_
