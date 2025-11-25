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
        nextMove = stageZeroLogic(gameState);
    } else if (gameState.stage == 1) {
        nextMove = stageOneLogic(gameState);
    } else if (gameState.stage == 2) {
        nextMove = stageTwoLogic(gameState);
    } else if (gameState.stage == 3) {
        nextMove = stageThreeLogic(gameState);
    }

    return nextMove;
}

bool Brain::validMove(GameState &gameState, int direction) {
    int playerRow = getPlayerRowInVisionArray(gameState);
    int playerCol = getPlayerColInVisionArray(gameState);

    if (direction == 1 && gameState.vision.at(playerRow - 1).at(playerCol) != '+') {
        return 1;
    }
    if (direction == 2 && gameState.vision.at(playerRow).at(playerCol - 1) != '+') {
        return 1;
    }
    if (direction == 3 && gameState.vision.at(playerRow + 1).at(playerCol) != '+') {
        return 1;
    }
    if (direction == 4 && gameState.vision.at(playerRow).at(playerCol + 1) != '+') {
        return 1;
    }
    return 0;
}

int Brain::stageZeroLogic(GameState &gameState) {
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

void Brain::checkForFood(GameState &gameState, int move) {
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

int Brain::stageOneLogic(GameState &gameState) { 
    //Get all food in current row
    int playerRow = getPlayerRowInVisionArray(gameState);
    int playerCol = getPlayerColInVisionArray(gameState);

    if (this->foodRemaining > 0) {
        if (this->prevMove == 4) {
            if (gameState.vision.at(playerRow).at(playerCol + 1) == '+' || gameState.vision.at(playerRow).at(playerCol + 1) == 'D') {
                checkForFood(gameState, 1);
                this->prevMove = 2;
                return 1;
            } else {
                checkForFood(gameState, 4);
                this->prevMove = 4;
                return this->prevMove;
            }
        }
        if (this->prevMove == 2) {
            if (gameState.vision.at(playerRow).at(playerCol - 1) == '+' || gameState.vision.at(playerRow).at(playerCol - 1) == 'D') {
                checkForFood(gameState, 1);
                this->prevMove = 4;
                return 1;
            } else {
                checkForFood(gameState, 2);
                this->prevMove = 2;
                return this->prevMove;
            }
        }
    } else {
        return stageZeroLogic(gameState);
    }
    
    return 1;
}


int Brain::stageTwoLogic(GameState &gameState) {
    if (validMove(gameState, 4) && this->prevDirection != 2) {
        this->prevDirection = 4;
        return 4;
    }
    if (validMove(gameState, 1) && this->prevDirection != 3) {
        this->prevDirection = 1;
        return 1;
    }
    if (validMove(gameState, 3) && this->prevDirection != 1) {
        this->prevDirection = 3;
        return 3;
    }
    if (validMove(gameState, 2) && this->prevDirection != 4) {
        this->prevDirection = 2;
        return 2;
    }
    return 0;
}

int Brain::stageThreeLogic(GameState &gameState) {
    for (unsigned int row = 0; row < gameState.vision.size(); row++) {
        for (unsigned int col = 0; col < gameState.vision.at(row).size(); col++) {
            char character = gameState.vision[row][col];
            if (character == 'A') {
                aPos[0]=  row;
                aPos[1]=  col;
            }
            if (character == 'B') {
                bPos[0]=  row;
                bPos[1]=  col;
            }
        }
    }
    if (aPos[0] == -1) {
        return stageTwoLogic(gameState);
    } else {
        std::cout << "Attempting to head towards " << aPos[0] << ", " << aPos[1] << "\n";
    }
    return 0;
}

