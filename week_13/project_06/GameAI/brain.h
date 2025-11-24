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
    Brain();                               // Constructor
    int getNextMove(GameState &gamestate); // Returns the next move for the AI
    int basicMovement(GameState &gameState);
    int getPlayerRowInVisionArray (GameState &gameState);
    int getPlayerColInVisionArray (GameState &gameState);
    int DirectionToMoveTowardsFood(GameState &gameState);
};

#endif // BRAIN_H