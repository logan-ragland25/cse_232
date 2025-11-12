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
    std::string convertToScientific(double value);
    std::string ToString();
    Measurement Add(Measurement value);
    Measurement Subtract(Measurement value);
    Measurement Multiply(Measurement value);
    Measurement Divide(Measurement value);
    Measurement RaisedToPower(int power);
    void changeUnits(std::string unit, int amount);
    void multiply(std::map<std::string, int> map);
    void denominate(std::map<std::string, int> map);
    void unitPow(int power);
};


#endif