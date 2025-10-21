#include <iostream>
#include "temperature.hpp"

int main() {
    Temperature t(13, 'C');
    // IsNear returns true if the first two arguments are less than the third argument apart.
    std::cout << t.AsCelsius() << "\n";
    std::cout << t.AsKelvin() << "\n";
    std::cout << t.AsRankine() << "\n";
    Temperature t2(45.6, 'R');
    std::cout << t2.AsFahrenheit() << "\n";
    // Be sure to test all combinations!
}