#include <iostream>

int Triple(int num) {
    return num * 3;
}

int Closest_Multiple_Of_13(int num) {
    if (num > 0) { 
        return (num + 6) / 13 * 13; 
    }
    if (num < 0) {
        return -1 * ((-1*num + 6) / 13 * 13);
    }
    return 0;
}

int main() {
    int input{};

    std::cin >> input;
    // std::cout << input * 2;

    std::cout << Closest_Multiple_Of_13(input);

    return 0;
}