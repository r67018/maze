#ifndef GAME_HPP
#define GAME_HPP


#include "maze.hpp"
#include "player.hpp"
#include "clear.hpp"


class Game
{
public:
    bool running = true;

    Game(int W, int H) : maze(W, H) , player(maze.start)
    {
        CONSOLE_CLEAR();
        maze.print();
    }

    #if !defined(_WIN64) || !defined(_WIN32)
    int kbhit();
    #endif
    void update();

private:
    Maze maze;
    Player player;
    Maze::State prev_state = Maze::State::start;
};


#endif
