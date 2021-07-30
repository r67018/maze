#include "game.hpp"
#include "clear.hpp"


#if defined(_WIN64) || defined(_WIN32)
    #include <conio.h>
    #define getchar getch
#elif defined(__linux__) || defined(__unix__)
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>

    int Game::kbhit()
    {
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if (ch != EOF) {
            ungetc(ch, stdin);
            return 1;
        }

        return 0;
    }
#endif


void Game::update()
{
    if (kbhit()) {
        // get pressed key
        int key = getchar();
        // next position
        Coord np = player.getMoveTo(key);
        Maze::State next_state = maze.field[np.x][np.y];
        if (next_state != Maze::State::wall) {
            // previous position
            Coord pp = player.p;
            // update player's position
            player.p = np;

            // restore the state
            maze.field[pp.x][pp.y] = prev_state;
            // save the state
            prev_state = maze.field[np.x][np.y];
            // update the state
            maze.field[np.x][np.y] = Maze::State::player;
            if (prev_state == Maze::State::goal) {
                running = false;
            }
            CONSOLE_CLEAR();
            maze.print();
        }
    }
}
