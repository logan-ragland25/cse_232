#include <iostream>

int main() {
    int input_a {}, input_b {}, input_c {};  

    std::cin >> input_a >> input_b >> input_c;

    int smallestDiff{};
    int diff1 = abs(input_a - input_b);
    int diff2 = abs(input_a - input_c);
    int diff3 = abs(input_b - input_c);

    if (diff1 <= diff2 && diff1 <= diff3) {
        smallestDiff = diff1;
    } else if (diff2 <= diff1 && diff2 <= diff3) {
        smallestDiff = diff2;
    } else if (diff3 <= diff1 && diff3 <= diff2) {
        smallestDiff = diff3;
    }

    std::cout << smallestDiff;
    return 0;
}