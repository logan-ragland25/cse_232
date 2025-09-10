#include <iostream>
#include <string>
#include <tuple>


std::tuple<int, int> computeAdditivePersistence(int num, int numComputations) {
    int sumOfDigits{0};

    while (num > 0) {
        // get last digit of thee number and add it to a sum of all digits
        int lastDigit = num % 10;
        sumOfDigits += lastDigit;
        // remove last digit from number
        num /= 10;
    }

    // Recursively call computeAdditivePersistence if there are 2 or more digits
    if (sumOfDigits > 9) {
        computeAdditivePersistence(sumOfDigits, ++numComputations);
    }
    

    return std::make_tuple(sumOfDigits, numComputations);
}

int main() {
    int num{0};

    // loop while still recieving input
    while (std::cin >> num) {
        // Check for negative numbers
        if (num < 0) {
            break;
        }
        int sum{0}, numAdditions{0};
        std::tie(sum, numAdditions) = computeAdditivePersistence(num, 1);
        std::cout << numAdditions << " " << sum << "\n";
    }

}
