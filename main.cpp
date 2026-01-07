#include <iostream>
#include "gameLogic.h"
#include <locale>

int main() {
    system("chcp 65001 > nul");

    Game game;
    initGame(game);
    gameLoop(game);
}
