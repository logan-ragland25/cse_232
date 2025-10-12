#include <iostream>

int main() {
    std::string input{};
    int sum{};

    while (std::cin >> input) {
        sum += std::stoi(input);
    }
    std::cout << sum;
    return 0;
}