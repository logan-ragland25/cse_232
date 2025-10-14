#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

double Fn(double x) {
    return -6 * pow(x, 2) + 5 * x + 3;
}

double Integral(double x) {
    return -2 * pow(x, 3) + (2.5) * pow(x, 2) + 3 * x;
}

double EstimateWithTraps(double a, double b, int n) {
    double deltaX = (b - a) / n;
    double totalArea{};

    for (int pos = 0; pos < n; pos++) {
        double lowerBound = Fn(a);
        double upperBound = Fn(a + deltaX);

        double area = (.5) * (lowerBound + upperBound) * deltaX;
        totalArea += area;
        a += deltaX;
    }

    return std::abs(totalArea);
}

void ToleranceTest(double lowerBoundry, double upperBoundry, int n, double tolerance) {
    double difference{};
    double trapezoidCount = (n / 2.0);
    do {
        trapezoidCount *= 2;
        double actualValue = std::abs(Integral(upperBoundry) - Integral(lowerBoundry));
        double estimateValue = EstimateWithTraps(lowerBoundry, upperBoundry, trapezoidCount);
        difference = std::abs(actualValue - estimateValue);
        std::cout << std::fixed << std::setprecision(4) << "Estimate:" << estimateValue << ", Number of Traps:" << static_cast<int>(trapezoidCount) << ", Diff:" << difference << "\n";
    } while (difference > tolerance); 
}


int main () {
    double lowerBoundry{}, upperBoundry{}, tolerance{};
    int numTrapizoids{};
    std::cout << "Lower Range: ";
    std::cin >> lowerBoundry;
    
    std::cout <<"\n";

    std::cout << "Upper Range: ";
    std::cin >> upperBoundry;

    std::cout <<"\n";

    std::cout << "Tolerance: ";
    std::cin >> tolerance;
    
    std::cout <<"\n";
    
    std::cout << "Initial trapezoid count: ";
    std::cin >> numTrapizoids;
    
    std::cout <<"\n";

    ToleranceTest(lowerBoundry, upperBoundry, numTrapizoids, tolerance);

    return 0;
}