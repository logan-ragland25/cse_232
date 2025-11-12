#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

#include <string>
#include <map>

class Measurement {
    
    double value{};
    double uncertainty{};
    std::string unit{};

public:
    std::map<std::string, int> unitMap{};
    Measurement (double value, double uncertainty, std::string unit);
    void alterUnits(std::string unit, int value);
    void copyUnits(Measurement &newMeasurement, Measurement measurement1, Measurement measurement2);
    std::string convertToScientific(double value);
    std::string ToString();
    Measurement Add(Measurement value);
    Measurement Subtract(Measurement value);
    Measurement Multiply(Measurement value);
    Measurement Divide(Measurement value);
};


#endif