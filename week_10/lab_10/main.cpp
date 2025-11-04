#include "matrix.hpp"
#include <vector>
#include <iostream>

int main () {
    int rows{}, cols{};
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "\nEnter the number of columns: ";
    std::cin >> cols;

    
    std::cout << "\nMatrix after initial creation:\n";
    std::vector<std::vector<int>> vec = create2DVector(rows,cols);
    print2DVector(vec);

    std::cout << "\nMatrix after filling with the sum of indices:\n";
    fillWithIndices(vec);
    print2DVector(vec);

    std::cout << "\nMatrix after doubling each element:\n";
    doubleElements(&vec);
    print2DVector(vec);
    return 0;
}