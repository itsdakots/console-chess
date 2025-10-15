// Unix: g++-14 -std=c++20 -Wall -Wextra -O2 -I src -o chess src/main.cpp src/board/board.cpp src/piece/piece.cpp src/util/screen/screen.cpp
// Windows: cl /std:c++20 /EHsc /I src src\main.cpp src\board\board.cpp src\piece\piece.cpp src\util\screen\screen.cpp /Fe:chess.exe
using namespace std;
#include <iostream>
#include "board/board.hpp"

int main() {
    auto board = Board();
    board.print();
}