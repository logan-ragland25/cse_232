#include "Measurement.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

Measurement::Measurement (double value, double uncertainty, std::string unit) {
    this->value = value;
    this->uncertainty = uncertainty;
    this->unit = unit;
}

std::string Measurement::convertToScientific(double value) {
    std::ostringstream oss;
    oss << std::scientific << std::setprecision(2);
    oss << value;
    return oss.str();
}

std::string Measurement::ToString() {
    std::ostringstream oss;
    oss << this->convertToScientific(this->value) << " +- " << this->convertToScientific(this->uncertainty) << " " << this->unit << " ";
    return oss.str();
}

Measurement Measurement::Add(Measurement val) {
    if (val.unit != this->unit) {
        throw std::invalid_argument("units are different");
    }

    double totalValue = this->value + val.value;
    double totalUncertainty = pow(pow(this->uncertainty, 2) + pow(val.uncertainty,2), 0.5);
    return Measurement(totalValue, totalUncertainty, this->unit);
}

Measurement Measurement::Subtract(Measurement val) {
    if (val.unit != this->unit) {
        throw std::invalid_argument("units are different");
    }

    double totalValue = this->value - val.value;
    double totalUncertainty = pow(pow(this->uncertainty, 2) + pow(val.uncertainty,2), 0.5);
    return Measurement(totalValue, totalUncertainty, this->unit);
}


Measurement Measurement::Multiply(Measurement val) {
    double totalValue = this->value * val.value;
    double totalUncertainty = pow(pow(this->uncertainty / this->value, 2) + pow(val.uncertainty / val.value,2), 0.5) * totalValue;
    std::string totalUnit = this->unit + " " + val.unit;
    return Measurement(totalValue, totalUncertainty, totalUnit);
}


Measurement Measurement::Divide(Measurement val) {
    double totalValue = this->value * val.value;
    double totalUncertainty = pow(pow(this->uncertainty / this->value, 2) + pow(val.uncertainty / val.value,2), 0.5) * totalValue;
    std::string totalUnit = this->unit + " " + val.unit;
    return Measurement(totalValue, totalUncertainty, totalUnit);
}