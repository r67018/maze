#ifndef CLEAR_HPP
#define CLEAR_HPP


#include <cstdlib>

# if defined(_WIN64) || defined(_WIN32)
# define CONSOLE_CLEAR() std::system("cls")
# elif defined(__linux__) || defined(__unix__)
# define CONSOLE_CLEAR() std::system("clear");
# endif


#endif
