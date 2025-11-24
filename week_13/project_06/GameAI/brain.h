#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include "../Game/game.h"
#include <cstdlib>
#include <ctime>

class Brain
{
public:
    Brain();                               // Constructor
    int getNextMove(GameState &gamestate); // Returns the next move for the AI
    bool validMove(GameState &gamestate, int move);
    int prevDirection{3};
    bool directionWithMostSpaces (GameState &GameState);
};

#endif // BRAIN_H