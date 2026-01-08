#include "saving.h"
#include <fstream>
#include <vector>

void saveGame(Game &game) {
    std::ofstream ofile("save.txt");
    if (ofile.is_open()) {
        ofile << game.player << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char cell = (game.board[i][j] == ' ') ? '_' : game.board[i][j];
                ofile << cell << "\n";
            }
        }
        ofile.close();
    }
}

bool loadGame(Game &game) {
    std::ifstream ifile("save.txt");
    if (!ifile.is_open()) return false;

    Game tempGame;
    tempGame.board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    char player;
    if (!(ifile >> player)) return false;
    tempGame.player = player;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char cell;
            if (!(ifile >> cell)) return false;
            tempGame.board[i][j] = (cell == '_') ? ' ' : cell;
        }
    }
    ifile.close();

    if (validateGameSave(tempGame)) {
        game = tempGame;
        return true;
    }
    return false;
}

bool validateGameSave(Game &tempGame) {
    if (tempGame.player != 'X' && tempGame.player != 'O') return false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char cell = tempGame.board[i][j];
            if (cell != 'X' && cell != 'O' && cell != ' ') return false;
        }
    }
    return true;
}