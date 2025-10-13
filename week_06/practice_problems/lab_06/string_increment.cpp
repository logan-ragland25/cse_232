#include <iostream>
#include <string>
#include <vector>

std::string StringIncrement(std::string input){
    //std::vector numbers{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::string numbers {"0123456789"};
    int position = input.length() - 1;
    while (input.at(position) == '9') {
        input.at(position) = '0';
        if (position == 0) {
            input.insert(0, "0");
            position += 1;
        }
        position -= 1;
    }
    
    char replacementNumber = numbers.at(numbers.find(input.at(position)) + 1);
    input.at(position) = replacementNumber;

    return input;
} 

int main() {
    std::cout << StringIncrement("9");
    return 0;
}