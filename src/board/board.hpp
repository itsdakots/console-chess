#ifndef BOARD
#define BOARD
#include "../piece/piece.hpp"

class Board {
    public:
        Board();
        void print();
        void rerender();
        ~Board();

    private:
        const int size = 8;
        char **board;
        void fillBoard();
        void freeBoard();
        void placePieces(int r);
        void placePawns();
};

#endif