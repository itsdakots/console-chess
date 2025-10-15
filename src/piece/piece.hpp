
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
    int y;
};

class Piece {

    public:
        ~Piece() = default;
        Piece(bool w);
        Piece();
        PieceType type;
        Position pos;
        std::string toString();
        friend std::ostream &operator<<(std::ostream &os, const Piece &obj);
        friend std::string &operator+(std::string &str, const Piece &obj);
        bool isWhite();
        static char getTypeChar(PieceType type);

    private:
        bool white;
        // Pure virtual (basically abstract function) = virtual bool canMove(Position pos) = 0;
        virtual bool canMove(Position pos);
};

class QueenPiece : public Piece {
    public:
        QueenPiece(bool w);
};

class RookPiece : public Piece {
    public:
        RookPiece(bool w);
};

class KnightPiece : public Piece {
    public:
        KnightPiece(bool w);
};

class BishopPiece : public Piece {
    public:
        BishopPiece(bool w);
};

class KingPiece : public Piece {
    public:
        KingPiece(bool w);
};

class PawnPiece : public Piece {
    public:
        PawnPiece(bool w);
};

#endif