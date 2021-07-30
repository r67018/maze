#include "maze.hpp"
#include "clear.hpp"


#ifdef PRINT_CREATE_PROCESS
    #include <iostream>
    #include <chrono>
    #include <thread>
    #define SLEEP_TIME 70
#endif


void Maze::print()
{
    for (int w = 0; w < W; w++) {
        for (int h = 0; h < H; h++) {
            switch (field[w][h]) {
                case State::road:
                    printf(" ");
                    break;

                case State::wall:
                    printf("#");
                    break;

                case State::start:
                    printf("\e[34ms\e[39m");
                    break;

                case State::goal:
                    printf("\e[31mg\e[39m");
                    break;

                case State::player:
                    printf("\e[33mP\e[39m");
                    break;
            }
        }
        printf("\n");
    }
}


int Maze::randOdd(const int gen_max)
{
    std::uniform_int_distribution<> randn(0, gen_max);
    int n = randn(mt);
    if (n % 2 == 0) n++;
    if (n > gen_max) n -= 2;
    return n;;
}


void Maze::dig(const Coord p)
{
    // p is the current position
    // np is the next posittion
    // nnp is the next position of np
    static const Coord dir[4] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int d  = rand3(mt);
    const int dd = d;

    while (1) {
        const int dx = dir[d].x;
        const int dy = dir[d].y;
        const Coord np  = { p.x + dx, p.y + dy };
        const Coord nnp = { np.x + dx, np.y + dy };

        if (nnp.x > 0 && nnp.x < W-1 && nnp.y > 0 && nnp.y < H-1 && field[nnp.x][nnp.y] == State::wall) {
            field[np.x][np.y] = State::road;
            field[nnp.x][nnp.y] = State::road;
            dist[np.x][np.y] = dist[p.x][p.y] + 1;
            dist[nnp.x][nnp.y] = dist[np.x][np.y] + 1;

            #ifdef PRINT_CREATE_PROCESS
            CONSOLE_CLEAR();
            print();
            std::cout << "Creating the maze ..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
            #endif

            dig(nnp);
        }
        d = (d + 1) % 4;
        if (d == dd) return;
    }
}


void Maze::create()
{
    field[start.x][start.y] = State::start;
    dig(start);

    // find the location farthest from the start
    int max_d = -1;
    for (int w = 0; w < W; w++) {
        for (int h = 0; h < H; h++) {
            if (max_d < dist[w][h]) {
                max_d = dist[w][h];
                goal = Coord(w, h);
            }
        }
    }
    field[goal.x][goal.y] = State::goal;
}
