#include <iostream>
#include <string>

int main () {
    std::string input{}, secretWord{}, output{};

    std::cout << "Give me a secret word: " << "\n";
    std::cin >> secretWord;

    int guess = 1;
    bool won = false;

    std::cout << "Give me a guess: " << "\n";
    while (guess <= 6 && std::cin >> input) {
        output = "";

        for (unsigned int pos = 0; pos < 5; pos++) {
            if (secretWord.find(input.at(pos)) != std::string::npos) {
                if (secretWord.at(pos) == input.at(pos)) {
                    output.push_back(secretWord.at(pos));
                } else {
                    output.push_back('?');
                }
            } else {
                output.push_back('.');
            }
        }
        if (output == secretWord) {
            std::cout << output << "\n";
            std::cout << "You Win!" << "\n";
            won = true;
            break;
        }
        guess++;
        std::cout << output << "\n";
        if (guess != 7) {
            std::cout << "Give me a guess: " << "\n";
        }
    }
    if (!won) {
        std::cout << "You Lose." << "\n";
    }
    return 0;
}