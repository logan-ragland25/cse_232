#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file {"text.txt"};
    std::string line{};

    while (std::getline(file, line)) {
        int start{0};
        if (line.find(" ", start) == std::string::npos) {
            std::cout << line.substr(start, line.length());
        }
        while (line.find(" ", start) != std::string::npos) {
            std::cout << line.substr(start, line.find(" ", start + 1) - start);
            if (line.find(" ", start + 1) != std::string::npos) {
                std::cout << ", ";
            }
            start =  line.find(" ", start + 1);
        }
        std::cout << "\n--------------------------------------\n";
    }

    return 0;
}