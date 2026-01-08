#ifndef SAVING
#define SAVING
#include "gameLogic.h"

void saveGame(Game &game);
bool loadGame(Game &game);
bool validateGameSave(Game &tempGame);

#endif