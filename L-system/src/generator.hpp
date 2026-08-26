#ifndef GENERATOR_HPP_
#define GENERATOR_HPP_

#include <vector>
#include <string>
#include <raylib.h>
#include <utility>

struct Turtle {
    Vector2 position;
};

typedef std::vector<std::pair<char, std::string>> tupl;
class Generator {
    std::string                               _axiom; /* the starting value */
    std::vector<std::pair<char, std::string>> _rules; /* a vector of rules */
  public:
    inline explicit Generator(std::vector<std::pair<char, std::string>> rules) {
        _rules = rules;
    }
    std::string generate(size_t iter, std::string gen);
    void        foward();
    void        rotate();
};
#endif // GENERATOR_HPP_
