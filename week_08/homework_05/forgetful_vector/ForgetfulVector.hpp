#ifndef FORGETFULVECTOR_HPP
#define FORGETFULVECTOR_HPP

#include <iostream>
#include <vector>

class ForgetfulVector {
    std::vector<int> forgetful{};
    std::vector<int> memory{};

    public:
        void push_back(int);
        int at(int);
        int size();
};

#endif