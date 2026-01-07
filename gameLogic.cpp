#include "gameLogic.h"
#include <iostream>

void initGame(Game &game) {
    game.board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    game.player = 'X';
}

void showBoard(Game &game) {
    std::cout << "  " << game.board[0][0] << " ┃ " << game.board[0][1] << " ┃ " << game.board[0][2] << "\n";
    std::cout << " ━━━╋━━━╋━━━ \n";
    std::cout << "  " << game.board[1][0] << " ┃ " << game.board[1][1] << " ┃ " << game.board[1][2] << "\n";
    std::cout << " ━━━╋━━━╋━━━ \n";
    std::cout << "  " << game.board[2][0] << " ┃ " << game.board[2][1] << " ┃ " << game.board[2][2] << "\n";
}