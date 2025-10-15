#include "board.hpp"
#include "../util/screen/screen.hpp"
#include "../util/constants.hpp"
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
            columns[y][x].pos.y = y;
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
    std::string str = "";
    str += std::string(BOARD_SIZE * 2 - 1, '-') + '\n';
    for (int x = 0; x < BOARD_SIZE; x++) {
        str += '|';
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            str += board[y][x].toString() + '|';
        }
        str += "\n " + std::string(BOARD_SIZE * 2 - 1, '-') + '\n';
    }

    screen::print(str);
}

void Board::rerender() {
    screen::clearConsole(17, 0);
    // Todo - Test Later and move to a separate namespace for these functions
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
    placePieces(0, false);
    placePieces(7, true);
}

void Board::placePawns() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][1] = PawnPiece(false);
        board[i][6] = PawnPiece(true);
    }
}

void Board::placePieces(int r, bool white) {
    board[0][r] = RookPiece(white);
    board[1][r] = KnightPiece(white);
    board[2][r] = BishopPiece(white);
    board[3][r] = QueenPiece(white);
    board[4][r] = KingPiece(white);
    board[5][r] = BishopPiece(white);
    board[6][r] = KnightPiece(white);
    board[7][r] = RookPiece(white);
}