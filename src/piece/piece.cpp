#include "piece.hpp"
#include "../screen/screen.hpp"
#include "../util/constants.hpp"
#include <format>

Piece::Piece(PieceType type, bool w) : white(w), type(type) {}
Piece::Piece() : white(false), type(Empty) {}

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
    if (white) return std::string(1, getTypeChar(type));
    return screen::formatText(std::string(1, getTypeChar(type)), BLACK_TEXT_SETTINGS);
}

bool Piece::isWhite() {
    return white;
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

// Queen
QueenPiece::QueenPiece(bool w) : Piece(Queen, w) {}

// Rook
RookPiece::RookPiece(bool w) : Piece(Rook, w) { }

// Knight
KnightPiece::KnightPiece(bool w) : Piece(Knight, w) { }

// Bishop
BishopPiece::BishopPiece(bool w) : Piece(Bishop, w) { }

// King
KingPiece::KingPiece(bool w) : Piece(King, w) { }

// Pawn
PawnPiece::PawnPiece(bool w) : Piece(Pawn, w) { }
// std::vector<Position> PawnPiece::availablePositions(Position pos) {
//     auto vect = std::vector<Position>();
// }
