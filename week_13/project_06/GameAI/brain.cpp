#include "brain.h"

Brain::Brain() {
}

int Brain::getNextMove(GameState &gamestate) {
    // AI logic to determine the next move based on the gamestate
    std::cout << prevDirection << "\n";
    // Generate a random number between 0 and 4 
    int nextMove = std::rand() % 5;
    
    directionWithMostSpaces(gamestate);

    // Continue in previous direction if possible
    bool valid = validMove(gamestate, prevDirection);
    if (valid && prevDirection != 0) {
        return prevDirection;
    }

    std::cout << valid << " was not valid";
    // If not possible, find a new move that is valid
    while (!valid) {
        nextMove = std::rand() % 5;
        valid = validMove(gamestate, nextMove);
        prevDirection = nextMove;
    }
    return nextMove;
}

bool Brain::validMove(GameState &gamestate, int move) {
    for (unsigned int i{1}; i < gamestate.vision.size(); i++) {
        for (unsigned int j{1}; j < gamestate.vision.at(i).size(); j++) {
            if (move == 0) {
                return 1;
            } 
            if (move == 1) {
                return (gamestate.vision.at(i - 1).at(j) == ' ' || gamestate.vision.at(i - 1).at(j) == '0');
            }
            if (move == 2) {
                return (gamestate.vision.at(i).at(j - 1) == ' ' || gamestate.vision.at(i).at(j - 1) == '0');
            }
            if (move == 3) {
                return (gamestate.vision.at(i + 1).at(j) == ' ' || gamestate.vision.at(i + 1).at(j) == '0');
            }
            if (move == 4) {
                return (gamestate.vision.at(i).at(j + 1) == ' ' || gamestate.vision.at(i).at(j + 1) == '0');
            }
        }
    }
    return 0;
}

bool Brain::directionWithMostSpaces (GameState &GameState) {
    std::vector<int> counts = {0, 0, 0, 0, 0};

    for (unsigned int up = 0; GameState.pos.at(0) - up - GameState.vision.size() >= 0; up--) {
        if (prevDirection == 1) { break; }
        counts.at(1) = counts.at(1) + 1;
    }
    for (unsigned int left = 0; GameState.pos.at(1) - left - GameState.vision.at(0).size() >= 0; left--) {
        if (prevDirection == 2) { break; }
        counts.at(2) = counts.at(2) + 1;
    }
    for (unsigned int down = 0; down <= GameState.vision.size(); down++) {
        if (prevDirection == 3) { break; }
        counts.at(3) = counts.at(3) + 1;
    }
    for (unsigned int right = 0; right <= GameState.vision.at(0).size(); right++) {
        if (prevDirection == 4) { break; }
        counts.at(4) = counts.at(4) + 1;
    }
    return 0;
}