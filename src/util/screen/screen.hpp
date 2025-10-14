#ifndef SCREEN
#define SCREEN
#include <string>

namespace screen {
    void clearConsole(int x, int y);

    void print(std::string s, bool newLine = false);
}

#endif