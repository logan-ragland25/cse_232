#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string input{};
    std::string finalOutput{};

    while (std::getline(std::cin, input)) {
        for (unsigned pos = 0; pos < input.length(); pos++) {
            if (input[pos] == ' ') {
                std::cout << input[pos] << "\n";
                // if (pos >= 5) {
                //     finalOutput += input.substr(0, pos) + " ";
                //     input = input.substr(pos + 1);
                //     pos = 0;
                // }
                // std::cout << input << " - " << input.length() << "\n";
            }
        }
        //finalOutput += "\n";
    }
    //std::cout << "\n\n" << finalOutput;
    return 0;
}