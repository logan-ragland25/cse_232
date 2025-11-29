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
    int aPos [2] = {-1,-1};
    int bPos [2] = {-1,-1};
    bool aCollected = 0;
    bool bCollected = 0;

    int prevMove {};
    int prevDirection {};
    int prevDirectionStage3 {};
    int foodRemaining{17};
    Brain();                               // Constructor
    int getNextMove(GameState &gamestate); // Returns the next move for the AI
    int chooseMove(GameState &gameState);
    int getPlayerRowInVisionArray (GameState &gameState);
    int getPlayerColInVisionArray (GameState &gameState);

    bool validMove(GameState &gameState, int direction);

    int stageZeroLogic(GameState &gameState);

    int stageOneLogic(GameState &gameState);
    void checkForFood(GameState &gameState, int move);
    
    int stageTwoLogic(GameState &gameState);

    
    int stageThreeLogic(GameState &gameState);
};

#endif // BRAIN_H