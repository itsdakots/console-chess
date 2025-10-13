#include "board.hpp"
#include <iostream>

// Board
Board::Board() {
    auto columns = new Piece *[BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        columns[i] = new Piece[BOARD_SIZE];
    }

    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            columns[y][x].type = Empty;
            columns[y][x].pos.y = y + 65;
            columns[y][x].pos.x = x;
        }
    }

    board = columns;
    fillBoard();
}

Board::~Board() {
    freeBoard();
}

void Board::print() {
    std::cout << " " << std::string(BOARD_SIZE * 2 - 1, '-') << '\n';
    for (int x = 0; x < BOARD_SIZE; x++) {
        std::cout << '|';
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            std::cout << board[y][x] << '|';
        }
        std::cout << "\n " << std::string(BOARD_SIZE * 2 - 1, '-') << '\n';
    }
}

void Board::rerender() {
    // Todo - Test Later and move to a separate namespace for these functions
    std::cout << "\033[" << 17 << ";" << 0 << "H" << "\033[J";
    print();
}

void Board::freeBoard() {

    for (int i = 0; i < BOARD_SIZE; i++) {
        delete board[i];
    }

    delete board;
    std::cout << "Board freed from memory.";
}

void Board::fillBoard() {
    placePawns();
    placePieces(0);
    placePieces(7);
}

void Board::placePawns() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][1] = PawnPiece();
        board[i][6] = PawnPiece();
    }
}

void Board::placePieces(int r) {
    board[0][r] = RookPiece();
    board[1][r] = KnightPiece();
    board[2][r] = BishopPiece();
    board[3][r] = QueenPiece();
    board[4][r] = KingPiece();
    board[5][r] = BishopPiece();
    board[6][r] = KnightPiece();
    board[7][r] = RookPiece();
}