#include "piece.hpp"
#include "../util/screen/screen.hpp"
#include "../util/constants.hpp"
#include <format>

Piece::Piece(bool w) : white(w), type(Empty) {}
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

// Todo - Override this for all piece types.
bool Piece::canMove(Position pos) {
    return false;
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

QueenPiece::QueenPiece(bool w) : Piece(w) { type = Queen; }
RookPiece::RookPiece(bool w) : Piece(w) { type = Rook; }
KnightPiece::KnightPiece(bool w) : Piece(w) { type = Knight; }
BishopPiece::BishopPiece(bool w) : Piece(w) { type = Bishop; }
KingPiece::KingPiece(bool w) : Piece(w) { type = King; }
PawnPiece::PawnPiece(bool w) : Piece(w) { type = Pawn; }
