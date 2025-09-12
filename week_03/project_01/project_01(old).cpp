#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> convertInputToVector(std::string input) {
    std::vector<std::string> wordList{};
    for (unsigned pos = 0; pos < input.length(); pos++) {
        if (input[pos] == ',') {
            wordList.push_back(input.substr(0, pos));
            input = input.substr(pos + 1);
            pos = 0;
        }
        else if (pos == input.length() - 1) {
            wordList.push_back(input.substr(0, pos + 1));
        }
        //std::cout << input << "\n";
    }
    return wordList;
}

bool checkForWords (std::string wordOne, std::string wordTwo, std::vector<std::string> wordList) {
    for (unsigned pos = 0; pos < wordList.size(); pos++) {

    }
}

int main()
{
    std::string input1, input2, listInput {};
    std::cin >> input1 >> input2;
    std::vector<std::string> wordList{};
    
    std::cin >> listInput;
    wordList = convertInputToVector(listInput);

}
