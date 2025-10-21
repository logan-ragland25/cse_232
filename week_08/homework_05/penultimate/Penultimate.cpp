#include "Penultimate.hpp"
#include <iostream>
#include <string>

Penultimate::Penultimate(std::string input) {
    this->previous = input;
}

std::string Penultimate::push_back(std::string input) {
    std::string toReturn = this->previous;
    this->previous = input;
    return toReturn;
}