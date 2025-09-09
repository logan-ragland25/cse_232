#include <iostream>
#include <string>

int main() {

    std::string input{};
    int previousASCII = 0;

    while (std::getline(std::cin, input)){
        for (char c : input) {
            int currentAscii = static_cast<int>(c);
            if (currentAscii > previousASCII) {
                std::cout << c;
            }
            else {
                std::cout << "_";
            }
            previousASCII = currentAscii;

        }
        std::cout << "\n";
    }

    return 0;
}