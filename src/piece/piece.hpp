
#ifndef PIECE
#define PIECE
#include <sstream>
enum PieceType
{
    Empty,
    Queen,
    Rook,
    Bishop,
    Knight,
    King,
    Pawn
};

struct Position {
    int x;
    char y;
};

class Piece {

    public:
        ~Piece() = default;
        PieceType type;
        Position pos;
        friend std::ostream& operator<<(std::ostream& os, const Piece& obj);
        static char getTypeChar(PieceType type);

    private:
        // Pure virtual (basically abstract function) = virtual bool canMove(Position pos) = 0;
        virtual bool canMove(Position pos);
};

class QueenPiece : Piece {
    public:
        QueenPiece();
};

class RookPiece : Piece {
    public:
        RookPiece();
};

class KnightPiece : Piece {
    public:
        KnightPiece();
};

class BishopPiece : Piece {
    public:
        BishopPiece();
};

class KingPiece : Piece {
    public:
        KingPiece();
};

class PawnPiece : Piece {
    public:
        PawnPiece();
};

#endif