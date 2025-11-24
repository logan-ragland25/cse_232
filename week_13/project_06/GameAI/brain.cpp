#include "brain.h"

Brain::Brain()
{
}

int Brain::getNextMove(GameState &gamestate)
{
    // AI logic to determine the next move based on the gamestate
    int nextMove = basicMovement(gamestate);
    this->prevPosition[0] = gamestate.pos[0];
    this->prevPosition[1] = gamestate.pos[1];
    prevMove = nextMove;
    return nextMove;
}

int Brain::basicMovement(GameState &gameState) {
    int playerRow = getPlayerRowInVisionArray(gameState);
    int playerCol = getPlayerColInVisionArray(gameState);

    int directionTowardsFood = DirectionToMoveTowardsFood(gameState);
    std::cout << "direction: " << directionTowardsFood << "\n";
    if (directionTowardsFood != 0) {
        return directionTowardsFood;
    }

    if (gameState.vision.at(playerRow).at(playerCol + 1) == ' ' || gameState.vision.at(playerRow).at(playerCol + 1) == '0') {
        return 4;
    } else if ((gameState.vision.at(playerRow + 1).at(playerCol) == ' ' || gameState.vision.at(playerRow + 1).at(playerCol) == '0') && prevMove != 1) {
        return 3;
    } else if (gameState.vision.at(playerRow - 1).at(playerCol) == ' ' || gameState.vision.at(playerRow - 1).at(playerCol) == '0') {
        return 1;
    }
    return 0;
}

int Brain::getPlayerRowInVisionArray (GameState &gameState) {
    for (unsigned int row = 0; row < gameState.vision.size(); row++) {
        for (unsigned int col = 0; col < gameState.vision.at(row).size(); col++) {
            char character = gameState.vision[row][col];
            if (character == '^' || character == 'v' || character == '<' || character == '>') {
                return row;
            }
        }
    }
    return -1;
}

int Brain::getPlayerColInVisionArray (GameState &gameState) {
    for (unsigned int row = 0; row < gameState.vision.size(); row++) {
        for (unsigned int col = 0; col < gameState.vision.at(row).size(); col++) {
            char character = gameState.vision[row][col];
            if (character == '^' || character == 'v' || character == '<' || character == '>') {
                return col;
            }
        }
    }
    return -1;
}

int Brain::DirectionToMoveTowardsFood(GameState &gameState) {
    //Get all food in current row
    int playerRow = getPlayerRowInVisionArray(gameState);
    int playerCol = getPlayerColInVisionArray(gameState);

    for (unsigned int col = 0; col < gameState.vision.at(playerRow).size(); col++) {
        if (gameState.vision.at(playerRow).at(col) == '0') {
            std::cout << "column with food: " << col << ", player col: " << playerCol << "\n";
            // If food is on the left
            if (playerCol - col > 0) {
                std::cout << "Food Detected to the Left!\n";
                if (gameState.vision.at(playerRow).at(playerCol - 1) != '+') {
                    return 2;
                }
            }
            // If food is on the right 
            else if (playerCol - col < 0) {
                std::cout << "Food Detected to the Right!\n";
                if (gameState.vision.at(playerRow).at(playerCol + 1) != '+') {
                    return 4;
                }
            }  
        }
    }
    return 0;
}