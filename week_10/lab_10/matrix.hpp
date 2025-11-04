#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

std::vector<std::vector<int>> create2DVector(int rows, int cols);
void print2DVector(std::vector<std::vector<int>> &vec);
void fillWithIndices(std::vector<std::vector<int>> &vec);
void doubleElements(std::vector<std::vector<int>>* vec);

#endif