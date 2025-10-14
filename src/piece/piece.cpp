#include "piece.hpp"
#include <format>

std::ostream& operator<<(std::ostream& os, const Piece& obj) {
    char c = obj.getTypeChar(obj.type);
    os << c;
    return os;
}

std::string &operator+(std::string &str, const Piece &obj) {
    str += std::string(1, obj.getTypeChar(obj.type));
    return str;
}

std::string Piece::toString() {
    return std::string(1, getTypeChar(type));
}

// Todo - Override this for all piece types.
bool Piece::canMove(Position pos) {
    return false;
}

char Piece::getTypeChar(PieceType type) {
    switch (type) {
        case Queen:
            return 'Q';
        case Rook:
            return 'R';
        case Bishop:
            return 'B';
        case Knight:
            return 'N';
        case King:
            return 'K';
        case Pawn:
            return 'P';
        case Empty:
            return ' ';
        }
        throw new std::runtime_error(std::format("Piece type {} is unknown", (int)type));
}

QueenPiece::QueenPiece() { type = Queen; }
RookPiece::RookPiece() { type = Rook; }
KnightPiece::KnightPiece() { type = Knight; }
BishopPiece::BishopPiece() { type = Bishop; }
KingPiece::KingPiece() { type = King; }
PawnPiece::PawnPiece() { type = Pawn; }
