#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>

std::string To_Digits(std::string input) {
    std::string lowercase = input;

    //https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), [](unsigned char c){ return std::tolower(c); });
    
    std::map<std::string, int> replacements = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    // // https://www.w3schools.com/cpp/cpp_maps.asp
    for (auto pair : replacements) {
        while (lowercase.find(pair.first) != std::string::npos) {
            int location = lowercase.find(pair.first);
            lowercase.replace(location, pair.first.length(), std::to_string(pair.second));
            input.replace(location, pair.first.length(), std::to_string(pair.second));
        }
    }

    return input;
}

int main () {
    std::string input{};
    
    std::getline(std::cin, input);

    std::cout << "\n" << To_Digits(input);

    return 0;
}