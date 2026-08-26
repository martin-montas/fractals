#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <utility>

#include "src/generator.hpp"

#define WIDTH  1000
#define HEIGHT 1000

int main() {
    // InitWindow(WIDTH, HEIGHT, "Fractal: L System");
    // SetTargetFPS(60);
    // while (!WindowShouldClose()) {
    //     BeginDrawing();
    //     EndDrawing();
    // }
    // CloseWindow();

    std::vector<std::tuple<char, std::string>> rules;

    std::pair<char, std::string> rule0 = std::make_pair('A', "AB");
    std::pair<char, std::string> rule1 = std::make_pair('B', "A");

    rules.push_back(rule0);
    rules.push_back(rule1);

    Generator* gen = new Generator(rules);
    gen->generate(3, "A");

    return 0;
}
