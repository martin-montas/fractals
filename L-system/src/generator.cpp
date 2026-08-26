#include "generator.hpp"
#include <iostream>

std::string Generator::generate(size_t iter, std::string gen) {
    if (iter == 0) {
        return gen;
    }
    std::string new_gen;
    for (auto r : _rules) {

        for (auto n : gen) {
            if (r.first == n) {
                new_gen += r.second;
            }
        }
    }
    std::cout << new_gen << std::endl;
    generate(iter - 1, new_gen);
}
