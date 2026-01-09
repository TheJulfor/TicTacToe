#ifndef GAME
#define GAME

#include <array>

struct Game {
    std::array<std::array<char, 3>, 3> board{};
    char player = 'X';
};

void initGame(Game &game);
void showBoard(const Game &game);
bool checkWin(const Game &game);
bool checkDraw(const Game &game);
bool makeMove(Game &game);
void gameLoop(Game &game);

#endif