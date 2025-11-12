#include "Measurement.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>

Measurement::Measurement (double value, double uncertainty, std::string unit) {
    this->value = value;
    this->uncertainty = uncertainty;
    this->unit = unit;
    this->unitMap.insert({unit, 1});
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

void Measurement::changeUnits(std::string unit, int amount) {
    if (this->unitMap.count(unit) > 0) {
        this->unitMap.at(unit) += amount;
    } else {
        this->unitMap.insert({unit, amount});
    }
}

void Measurement::multiply(std::map<std::string, int> map) {
    for (std::pair<const std::string, int> entry : map) {
        if (this->unitMap.count(entry.first) > 0) {
            this->unitMap.at(entry.first) += entry.second;
        } else {
            this->unitMap.insert({entry.first, entry.second});
        }
    } 
}

void Measurement::denominate(std::map<std::string, int> map) {
    for (std::pair<const std::string, int> entry : map) {
        if (this->unitMap.count(entry.first) > 0) {
            this->unitMap.at(entry.first) += -1 * entry.second;
        } else {
            this->unitMap.insert({entry.first, -1 * entry.second});
        }
    } 
}

Measurement Measurement::Add(Measurement val) {
    if (val.unit != this->unit) {
        throw std::invalid_argument("units are different");
    } else {
        double totalValue = this->value + val.value;
        double totalUncertainty = pow(pow(this->uncertainty, 2) + pow(val.uncertainty,2), 0.5);
        Measurement newMeasurement = Measurement(totalValue, totalUncertainty, this->unit);
        newMeasurement.unitMap = this->unitMap;
        return newMeasurement;
    }
}

Measurement Measurement::Subtract(Measurement val) {
    if (val.unit != this->unit) {
        throw std::invalid_argument("units are different");
    } else {
        double totalValue = this->value - val.value;
        double totalUncertainty = pow(pow(this->uncertainty, 2) + pow(val.uncertainty,2), 0.5);
        Measurement newMeasurement = Measurement(totalValue, totalUncertainty, this->unit);
        newMeasurement.unitMap = this->unitMap;
        return newMeasurement;
    }    
}

Measurement Measurement::Multiply(Measurement val) {
    double totalValue = this->value * val.value;
    double totalUncertainty = pow(pow(this->uncertainty / this->value, 2) + pow(val.uncertainty / val.value,2), 0.5) * totalValue;
    std::string totalUnit = this->unit + " " + val.unit;
    Measurement newMeasurement = Measurement(totalValue, totalUncertainty, totalUnit);
    newMeasurement.unitMap = this->unitMap;
    newMeasurement.multiply(val.unitMap);
    return newMeasurement;
}


Measurement Measurement::Divide(Measurement val) {
    double totalValue = this->value / val.value;
    double totalUncertainty = pow(pow(this->uncertainty / this->value, 2) + pow(val.uncertainty / val.value,2), 0.5) * totalValue;
    std::string totalUnit = this->unit + " " + val.unit;
    Measurement newMeasurement = Measurement(totalValue, totalUncertainty, totalUnit);
    newMeasurement.unitMap = this->unitMap;
    newMeasurement.denominate(val.unitMap);
    return newMeasurement;
}