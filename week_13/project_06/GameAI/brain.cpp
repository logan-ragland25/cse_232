#include "brain.h"

Brain::Brain()
{
}

int Brain::getNextMove(GameState &gamestate)
{
    // AI logic to determine the next move based on the gamestate

    // Generate a random number between 0 and 4
    int nextMove = std::rand() % 5;
    return nextMove;
}