#include "Measurement.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

Measurement::Measurement (double value, double uncertainty, std::string unit) {
    this->value = value;
    this->uncertainty = uncertainty;
    this->unit = unit;
}

void Measurement::alterUnits(std::string unit, int value) {
    if (this->unitMap.find(unit) != this->unitMap.end()) {
        this->unitMap.at(unit) = this->unitMap.at(unit) + value;
    } else {
        this->unitMap.insert(this->unitMap.begin(), {unit, value});
    }
}

std::string Measurement::convertToScientific(double value) {
    std::ostringstream oss;
    oss << std::scientific << std::setprecision(2);
    oss << value;
    return oss.str();
}

std::string Measurement::ToString() {
    std::ostringstream oss;
    std::ostringstream totalUnit;
    for (std::pair<const std::string, int> entry : this->unitMap) {
        if (entry.second == 1) {
            totalUnit << entry.first << " ";
        } else {
            totalUnit << entry.first << "^" << entry.second << " ";
        }
    } 

    oss << this->convertToScientific(this->value) << " +- " << this->convertToScientific(this->uncertainty) << " " << totalUnit.str();
    return oss.str();
}

Measurement Measurement::Add(Measurement val) {
    if (val.unit != this->unit) {
        throw std::invalid_argument("units are different");
    }

    double totalValue = this->value + val.value;
    double totalUncertainty = pow(pow(this->uncertainty, 2) + pow(val.uncertainty,2), 0.5);
    Measurement newMeasurement = Measurement(totalValue, totalUncertainty, this->unit);
    newMeasurement.alterUnits(newMeasurement.unit, 1);
    return newMeasurement;
}

Measurement Measurement::Subtract(Measurement val) {
    if (val.unit != this->unit) {
        throw std::invalid_argument("units are different");
    }

    double totalValue = this->value - val.value;
    double totalUncertainty = pow(pow(this->uncertainty, 2) + pow(val.uncertainty,2), 0.5);
    Measurement newMeasurement = Measurement(totalValue, totalUncertainty, this->unit);
    newMeasurement.alterUnits(newMeasurement.unit, 1);
    return newMeasurement;
}

Measurement Measurement::Multiply(Measurement val) {
    double totalValue = this->value * val.value;
    double totalUncertainty = pow(pow(this->uncertainty / this->value, 2) + pow(val.uncertainty / val.value,2), 0.5) * totalValue;
    std::string totalUnit = this->unit + " " + val.unit;
    Measurement newMeasurement = Measurement(totalValue, totalUncertainty, totalUnit);
    newMeasurement.alterUnits(this->unit, 1);
    newMeasurement.alterUnits(val.unit, 1);
    return newMeasurement;
}


Measurement Measurement::Divide(Measurement val) {
    double totalValue = this->value / val.value;
    double totalUncertainty = pow(pow(this->uncertainty / this->value, 2) + pow(val.uncertainty / val.value,2), 0.5) * totalValue;
    std::string totalUnit = this->unit + " " + val.unit;
    Measurement newMeasurement = Measurement(totalValue, totalUncertainty, totalUnit);
    newMeasurement.alterUnits(this->unit, 1);
    newMeasurement.alterUnits(val.unit, -1);
    return newMeasurement;
}