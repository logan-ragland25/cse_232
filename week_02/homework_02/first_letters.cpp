#include <iostream>
#include <string>
#include <vector>

int main() {

    std::string finalOutput {};
    std::string input{};
    std::vector<char> letters {};

    while (std::cin >> input) {
        if ((static_cast<int>(input[0]) >= 65 && static_cast<int>(input[0]) <= 90) || (static_cast<int>(input[0]) >= 97 && static_cast<int>(input[0]) <= 122)) {
                finalOutput += input[0];
            }
        for (unsigned int pos = 1; pos < input.length(); pos++) {
            int ascii = static_cast<int>(input[pos]);
            int prevAscii = static_cast<int>(input[pos - 1]);
            if (((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) && (!(prevAscii >= 65 && prevAscii <= 90) && !(prevAscii >= 97 && prevAscii <= 122))) {
                finalOutput += input[pos];
            }
        }
    }

    std::cout << finalOutput << "\n";

    return 0;
}