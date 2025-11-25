#include "brain.h"

Brain::Brain()
{
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

int Brain::getNextMove(GameState &gamestate)
{
    // AI logic to determine the next move based on the gamestate
    int nextMove = chooseMove(gamestate);
    // this->prevPosition[0] = gamestate.pos[0];
    // this->prevPosition[1] = gamestate.pos[1];
    return nextMove;
}

int Brain::chooseMove(GameState &gameState) {
    int nextMove{};

    if (gameState.stage == 0) {
        nextMove = stageOneLogic(gameState);
    } else if (gameState.stage == 1) {
        nextMove = stageTwoLogic(gameState);
    }

    return nextMove;
}

int Brain::stageOneLogic(GameState &gameState) {
    int playerRow = getPlayerRowInVisionArray(gameState);
    int playerCol = getPlayerColInVisionArray(gameState);

    if (gameState.vision.at(playerRow).at(playerCol + 1) == ' ') {
        this->prevMove = 4;
        return 4;
    } else if ((gameState.vision.at(playerRow + 1).at(playerCol) == ' ') && this->prevMove != 1) {
        this->prevMove = 3;
        return 3;
    } else if (gameState.vision.at(playerRow - 1).at(playerCol) == ' ') {
        this->prevMove = 1;
        return 1;
    }
    return 0;
}

void Brain::checkForFood(int move, GameState &gameState) {
    int playerRow = getPlayerRowInVisionArray(gameState);
    int playerCol = getPlayerColInVisionArray(gameState);

    if (move == 1) {
        if (gameState.vision.at(playerRow - 1).at(playerCol) == '0') {
            this->foodRemaining--;
        }
    }
    if (move == 2) {
        if (gameState.vision.at(playerRow).at(playerCol - 1) == '0') {
            this->foodRemaining--;
        }
    }
    if (move == 3) {
        if (gameState.vision.at(playerRow + 1).at(playerCol) == '0') {
            this->foodRemaining--;
        }
    }
    if (move == 4) {
        if (gameState.vision.at(playerRow).at(playerCol + 1) == '0') {
            this->foodRemaining--;
        }
    }
}

int Brain::stageTwoLogic(GameState &gameState) { 
    //Get all food in current row
    int playerRow = getPlayerRowInVisionArray(gameState);
    int playerCol = getPlayerColInVisionArray(gameState);

    std::cout << this->foodRemaining << "\n";
    if (this->foodRemaining > 0) {
        if (this->prevMove == 4) {
            if (gameState.vision.at(playerRow).at(playerCol + 1) == '+' || gameState.vision.at(playerRow).at(playerCol + 1) == 'D') {
                checkForFood(1, gameState);
                this->prevMove = 2;
                return 1;
            } else {
                checkForFood(4, gameState);
                this->prevMove = 4;
                return this->prevMove;
            }
        }
        if (this->prevMove == 2) {
            if (gameState.vision.at(playerRow).at(playerCol - 1) == '+' || gameState.vision.at(playerRow).at(playerCol - 1) == 'D') {
                checkForFood(1, gameState);
                this->prevMove = 4;
                return 1;
            } else {
                checkForFood(2, gameState);
                this->prevMove = 2;
                return this->prevMove;
            }
        }
    } else {
        return stageOneLogic(gameState);
    }
    
    return 1;
}