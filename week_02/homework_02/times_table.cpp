#include <iostream>
#include <string>
#include <vector>

int main() {
    int col_start{}, col_end{}, row_start{}, row_end{};
    std::cin >> col_start >> col_end >> row_start >> row_end;

    if (col_start > col_end) {
        int temp = col_start;
        col_start = col_end;
        col_end = temp;
    }

    if (row_start > row_end) {
        int temp = row_start;
        row_start = row_end;
        row_end = temp;
    }


    /*for (int col = col_start; col <= col_end; col++) {
        for (int row = row_start; row <= row_end; row++) {
            std::cout << col << "*" << row << "=" << col*row;
            if (row != row_end) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }*/
        
    for (int row = row_start; row <= row_end; row++) {
        for (int col = col_start; col <= col_end; col++) {
            std::cout << row << "*" << col << "=" << row*col;
            if (col != col_end) {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}