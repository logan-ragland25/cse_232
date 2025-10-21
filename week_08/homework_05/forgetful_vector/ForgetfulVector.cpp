#include "ForgetfulVector.hpp"
#include <iostream>
#include <vector>

void ForgetfulVector::push_back(int value) {
    bool found = false;

    for (unsigned int pos = 0; pos < this->memory.size(); pos++) {
        if (memory.at(pos) == value) {
            found = true;
        }
    }
    if (found) {
        this->forgetful.push_back(value);
    } else {
        this->memory.push_back(value);
    }
}

int ForgetfulVector::at(int pos) {
    return this->forgetful.at(pos);
}
int ForgetfulVector::size() {
    return forgetful.size();
}
