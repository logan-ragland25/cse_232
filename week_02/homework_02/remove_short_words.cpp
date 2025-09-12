#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string input{};
    std::string finalOutput{};

    while (std::getline(std::cin, input)) {
        for (unsigned pos = 0; pos < input.length(); pos++) {
           

            if (input[pos] == ' ') {
                //std::cout << input.substr(0, pos) << " - word length: " << pos << "\n";

                if (pos >= 5) {
                    finalOutput += input.substr(0, pos + 1);
                }

                input = input.substr(pos + 1);

                pos = 0;
            }

            if (pos == input.length() - 1) {
                if (pos >= 4) {
                    finalOutput += input.substr(0, pos + 1) + " ";
                    //std::cout << input.substr(0, pos + 1) << " - word length: " << pos + 1 << "\n";
                }
                finalOutput += "\n";
            }
        }
        finalOutput += "\n";
    }
    std::cout << "\n" << finalOutput;
    return 0;
}
