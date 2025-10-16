
#ifndef PIECE
#define PIECE
#include "../util/structs.hpp"
#include <sstream>
#include <vector>
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

class Piece {

    public:
        ~Piece() = default;
        Piece(PieceType type, bool w);
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

        // protected:
        //     virtual std::vector<Position> availablePositions(Position pos) = 0;
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

    // protected:
    //     std::vector<Position> availablePositions(Position pos) override;
};

#endif