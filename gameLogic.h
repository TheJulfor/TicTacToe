#ifndef GAME
#define GAME
#include <vector>

struct Game {
    std::vector<std::vector<char>> board;
    char player = 'X';
};

void initGame(Game &game);
void showBoard(Game &game);

#endif