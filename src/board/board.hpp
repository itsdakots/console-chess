#ifndef BOARD
#define BOARD
#define BOARD_SIZE 8
#include "../piece/piece.hpp"

class Board
{
public:
    Board();
    void print();
    void rerender();
    ~Board();

private:
    Piece **board;
    void fillBoard();
    void freeBoard();
    void placePieces(int r);
    void placePawns();
};

#endif