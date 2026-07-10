#ifndef GENERATOR_HPP_
#define GENERATOR_HPP_
#include <vector>
#include "line.hpp"
#include <raylib.h>
#include <raymath.h>

class Generator {
  public:
    std::vector<Line> lines;
    void              divide_line(Line line);
};

#endif // GENERATOR_HPP_
