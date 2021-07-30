#ifndef MAZE_HPP
#define MAZE_HPP


#include "coord.hpp"

#include <vector>
#include <random>


class Maze
{
public:
    enum class State
    {
        road,
        wall,
        start,
        goal,
        player
    };

    std::vector<std::vector<State>> field;
    Coord start;
    Coord goal;

    Maze(int W, int H) : W(W), H(H)
    {
        field.assign(W, std::vector<State>(H, State::wall));
        dist.assign(W, std::vector<int>(H));

        mt.seed(rd());
        rand3 = std::uniform_int_distribution<>(0, 3);

        start = Coord(randOdd(W-1), randOdd(H-1));
        dist[start.x][start.y] = 0;
        create();
    }

    void print();

private:
    const int W;
    const int H;
    std::vector<std::vector<int>> dist;
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<> rand3;


    int randOdd(const int gen_max);
    void dig(const Coord p);
    void create();
};


#endif
