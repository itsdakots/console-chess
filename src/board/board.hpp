#ifndef BOARD
#define BOARD
#define BOARD_SIZE 8
#include "../piece/piece.hpp"
#include "../util/structs.hpp"

class Board
{
public:
    Board();
    void print();
    void rerender();
    bool isPosOccupied(Position pos);
    bool movePiece(Position start, Position end);
    ~Board();

private:
    Piece **board;
    void fillBoard();
    void freeBoard();
    void placePieces(int r, bool white);
    void placePawns();
};

#endif