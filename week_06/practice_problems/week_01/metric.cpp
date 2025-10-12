#include <iostream>
#include <string>

int main() {
    std::string value1{}, unit1{}, value2{}, unit2{};
    std::cin >> value1 >> unit1 >> value2 >> unit2;
    
    double convertedValue1 = std::stod(value1);
    double convertedValue2 = std::stod(value2);
    
    if (unit1 == "mm") {
        convertedValue1 /= 1000;
    } else if (unit1 == "cm") {
        convertedValue1 /= 100;
    } else if (unit1 == "km") {
        convertedValue1 *= 1000;
    }

    if (unit2 == "mm") {
        convertedValue2 /= 1000;
    } else if (unit2 == "cm") {
        convertedValue2 /= 100;
    } else if (unit2 == "km") {
        convertedValue2 *= 1000;
    }

    if (convertedValue1 > convertedValue2) {
        std::cout << "1 > 2";
    } else if (convertedValue1 < convertedValue2) {
        std::cout << "1 < 2";
    } else {
        std::cout << "1 == 2";
    }

    return 0;
}