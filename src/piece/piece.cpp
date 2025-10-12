#include "piece.hpp"
#include <format>

std::ostream& operator<<(std::ostream& os, const Piece& obj) {
    char c = obj.getTypeChar(obj.type);
    os << c;
    return os;
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
        }
        throw new std::runtime_error(std::format("Piece type {} is unknown", (int)type));
}