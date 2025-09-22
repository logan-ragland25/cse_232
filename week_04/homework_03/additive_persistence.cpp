#include <iostream>
#include <string>
#include <vector>

int main() {
	int value{0};

	while (std::cin >> value) {
        while (value / 100 > 0) {
            int sum{};

            while (value > 0) {
                sum += value % 100;
                value /= 100;
            }
            
            value = sum;
        }

        std::cout << value << "\n";
	}
}