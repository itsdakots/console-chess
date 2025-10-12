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
    // Todo - Test Later
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
        // Todo - Figure out polymorphism for this.
        board[i][1].type = Pawn;
        board[i][6].type = Pawn;
    }
}

void Board::placePieces(int r) {
    board[0][r].type = Rook;
    board[1][r].type = Knight;
    board[2][r].type = Bishop;
    board[3][r].type = Queen;
    board[4][r].type = King;
    board[5][r].type = Bishop;
    board[6][r].type = Knight;
    board[7][r].type = Rook;
}