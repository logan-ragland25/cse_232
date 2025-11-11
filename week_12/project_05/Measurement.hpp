#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

#include <string>
#include <map>

class Measurement {
    
    double value{};
    double uncertainty{};
    std::string unit{};
    std::map<std::string, int> unitMap{};

public:
    Measurement (double value, double uncertainty, std::string unit);
    void Measurement::alterUnits(std::string unit, int value);
    std::string convertToScientific(double value);
    std::string ToString();
    Measurement Add(Measurement value);
    Measurement Subtract(Measurement value);
    Measurement Multiply(Measurement value);
    Measurement Divide(Measurement value);
};


#endif