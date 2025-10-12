
#ifndef PIECE
#define PIECE
#include <sstream>
enum PieceType
{
    Queen,
    Rook,
    Bishop,
    Knight,
    King,
    Pawn
};

class Piece {

    public:
        PieceType type;
        Piece(PieceType type);
        static char getTypeChar(PieceType type);

    private:
        
};

#endif