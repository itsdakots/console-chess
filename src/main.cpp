// g++-14 -std=c++20 -Wall -Wextra -O2 -I src -o test src/main.cpp src/board/board.cpp src/piece/piece.cpp
using namespace std;
#include <iostream>
#include "board/board.hpp"

int main() {
    auto board = Board();
    board.print();
}