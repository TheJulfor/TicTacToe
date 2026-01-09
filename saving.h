#ifndef SAVING
#define SAVING
#include "gameLogic.h"

void saveGame(const Game &game);
bool loadGame(Game &game);
bool validateGameSave(const Game &tempGame);

#endif