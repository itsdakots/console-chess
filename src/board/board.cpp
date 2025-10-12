#include "board.hpp"
#include <iostream>

Board::Board() {
    auto columns = new char *[size];

    for (int i = 0; i < size; i++)
    {
        columns[i] = new char[size];
    }

    board = columns;
    fillBoard();
}

Board::~Board() {
    freeBoard();
}

void Board::print() {
    std::cout << " " << std::string(size * 2 - 1, '-') << '\n';
    for (int x = 0; x < size; x++) {
        std::cout << '|';
        for (int y = 0; y < size; y++)
        {
            std::cout << board[y][x] << '|';
        }
        std::cout << "\n " << std::string(size * 2 - 1, '-') << '\n';
    }
}

void Board::rerender() {
    // Todo - Test Later
    std::cout << "\033[" << 17 << ";" << 0 << "H" << "\033[J";
    print();
}

// Privates
void Board::freeBoard() {

    for (int i = 0; i < size; i++) {
        delete board[i];
    }

    delete board;
    std::cout << "Board freed from memory.";
}

void Board::fillBoard() {
    placePawns();
    placePieces(0);
    placePieces(7);

    for (int x = 2; x < 6; x++) {
        for (int y = 0; y < size; y++) {
            board[y][x] = ' ';
        }
    }
}

void Board::placePawns() {
    for (int i = 0; i < size; i++) {
        board[i][1] = 'P';
        board[i][6] = 'P';
    }
}

void Board::placePieces(int r) {
    board[0][r] = 'R';
    board[1][r] = 'N';
    board[2][r] = 'B';
    board[3][r] = 'Q';
    board[4][r] = 'K';
    board[5][r] = 'B';
    board[6][r] = 'N';
    board[7][r] = 'R';
}