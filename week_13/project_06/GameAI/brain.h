#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include "../Game/game.h"
#include <cstdlib>
#include <ctime>

class Brain
{
public:
    int prevPosition [2] = {1,1};
    int prevMove {};
    int foodRemaining{17};
    Brain();                               // Constructor
    int getNextMove(GameState &gamestate); // Returns the next move for the AI
    int chooseMove(GameState &gameState);
    int getPlayerRowInVisionArray (GameState &gameState);
    int getPlayerColInVisionArray (GameState &gameState);

    int stageOneLogic(GameState &gameState);

    int stageTwoLogic(GameState &gameState);
    void checkForFood(int move, GameState &gameState);
};

#endif // BRAIN_H