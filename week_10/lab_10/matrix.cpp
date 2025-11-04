#include "matrix.hpp"

#include <vector>
#include <iostream>

std::vector<std::vector<int>> create2DVector(int rows, int cols) {
    std::vector<std::vector<int>> vec{};
    for (int row = 0; row < rows; row++) {
        vec.push_back(std::vector<int>(0));
        for (int col = 0; col < cols; col++) {
            vec.at(row).push_back(0);
        }
    }
    
    return vec;
}

void print2DVector(std::vector<std::vector<int>> &vec) {
    for (unsigned int row = 0; row < vec.size(); row++) {
        for (unsigned int col = 0; col < vec.at(row).size(); col++) {
            std::cout << vec.at(row).at(col) << " ";
        }
        std::cout << "\n";
    }
    
}

void fillWithIndices(std::vector<std::vector<int>> &vec) {
    for (unsigned int row = 0; row < vec.size(); row++) {
        for (unsigned int col = 0; col < vec.at(row).size(); col++) {
            vec.at(row).at(col) = row + col;
        }
    }
}

void doubleElements(std::vector<std::vector<int>>* vec) {
    for (unsigned int row = 0; row < (*vec).size(); row++) {
        for (unsigned int col = 0; col < (*vec).at(row).size(); col++) {
            (*vec).at(row).at(col) *= 2;
        }
    }
}