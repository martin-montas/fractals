#ifndef GENERATOR_HPP_
#define GENERATOR_HPP_

#include <vector>
#include <string>
#include <tuple>

typedef std::vector<std::tuple<std::string, std::string>> tupl;
class Generator {
    std::string _source; /* the starting value */
    tupl        _rules;  /* a vector of rules */
  public:
    inline explicit Generator(std::string source, tupl rules) {
        _source = source;
        _rules  = rules;
    }
    generate();
};
#endif // GENERATOR_HPP_
