#include <string>
#include <iostream>

int Repeat(int input) {
    return input * 2;
}

std::string Repeat(char input) {
    std::string output{input};
    return output + output;
}

std::string Repeat(std::string input) {
    return input + " " + input;
}