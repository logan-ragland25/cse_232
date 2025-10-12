#include <iostream>
#include <fstream>

int main() {
    std::ofstream output {"text.txt"};
    output << "Hello";
    output.close();
    
    return 0;
}