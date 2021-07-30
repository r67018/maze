#include "game.hpp"

#include <iostream>
#include <chrono>


#define WIDTH  21
#define HEIGHT 25


int main()
{
    Game game(WIDTH, HEIGHT);

    auto start = std::chrono::system_clock::now();
    while (game.running) {
        game.update();
    }
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Clear time: " << elapsed / 1000 << "s" << std::endl;

    return 0;
}
