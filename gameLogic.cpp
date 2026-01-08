#include "gameLogic.h"
#include <iostream>
#include <fstream>

void initGame(Game &game) {
    game.board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    game.player = 'X';
}

void showBoard(Game &game) {
    std::cout << "  " << game.board[0][0] << " ┃ " << game.board[0][1] << " ┃ " << game.board[0][2] << "\n";
    std::cout << " ━━━╋━━━╋━━━ \n";
    std::cout << "  " << game.board[1][0] << " ┃ " << game.board[1][1] << " ┃ " << game.board[1][2] << "\n";
    std::cout << " ━━━╋━━━╋━━━ \n";
    std::cout << "  " << game.board[2][0] << " ┃ " << game.board[2][1] << " ┃ " << game.board[2][2] << "\n\n";
}

bool checkWin(Game &game) {
    for (int i = 0; i < 3; i++) { // rows
        if (game.board[i][0] == game.board[i][1] && game.board[i][1] == game.board[i][2]) {
            if (game.board[i][0] == 'X' || game.board[i][0] == 'O') return true;
        }
    }

    for (int i = 0; i < 3; i++) { // columns
        if (game.board[0][i] == game.board[1][i] && game.board[1][i] == game.board[2][i]) {
            if (game.board[0][i] == 'X' || game.board[0][i] == 'O') return true;
        }
    }

    // diagonal
    if (game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2]) {
        if (game.board[0][0] == 'X' || game.board[0][0] == 'O') return true;
    }
    if (game.board[0][2] == game.board[1][1] && game.board[1][1] == game.board[2][0]) {
        if (game.board[0][2] == 'X' || game.board[0][2] == 'O') return true;
    }

    return false;
}

bool checkDraw(Game &game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game.board[i][j] != 'X' && game.board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(Game &game) {
    std::string input;
    std::cout << "Игрок " << game.player << ", укажите номер клетки (1-9): ";
    std::getline(std::cin, input);

    if (input.length() != 1 || !std::isdigit(input[0])) {
        std::cout << "Неверный ввод! Выберите клетку от 1 до 9.\n\n";
        return;
    }

    int choice = std::stoi(input);
    int x = (choice - 1) / 3;
    int y = (choice - 1) % 3;

    if (game.board[x][y] != ' ') {
        std::cout << "Клетка уже занята!\n\n";
        return;
    }

    game.board[x][y] = game.player;
    game.player = (game.player == 'X') ? 'O' : 'X';
}

void gameLoop(Game &game) {
    bool gameOver = false;
    while (!gameOver) {
        showBoard(game);
        makeMove(game);

        char currentPlayer = (game.player == 'X') ? 'O' : 'X';
        if (checkWin(game)) {
            showBoard(game);
            std::cout << "Игра окончена! Игрок " << currentPlayer << " победил!\n";
            gameOver = true;
        }
        else if (checkDraw(game)) {
            showBoard(game);
            std::cout << "Ничья! Свободных клеток не осталось.\n";
            gameOver = true;
        }
    }
}