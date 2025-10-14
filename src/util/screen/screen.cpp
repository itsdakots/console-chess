#include "screen.hpp"
#include <iostream>

namespace screen {
    void clearConsole(int x, int y) {
        std::cout << "\033[" << x << ";" << y << "H" << "\033[J";
    }

    void print(std::string s, bool newLine) {
        std::cout << s;
        if (newLine)
            std::cout << '\n';
    }
}