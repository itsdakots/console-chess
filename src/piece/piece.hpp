
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

class QueenPiece : public Piece {
    public:
        QueenPiece();
};

class RookPiece : public Piece {
    public:
        RookPiece();
};

class KnightPiece : public Piece {
    public:
        KnightPiece();
};

class BishopPiece : public Piece {
    public:
        BishopPiece();
};

class KingPiece : public Piece {
    public:
        KingPiece();
};

class PawnPiece : public Piece {
    public:
        PawnPiece();
};

#endif