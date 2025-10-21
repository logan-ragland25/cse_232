#ifndef PENULTIMATE_HPP
#define PENULTIMATE_HPP

#include <string>

class Penultimate {
    std::string previous{};

public:
    Penultimate (std::string);

    std::string push_back(std::string);
};


#endif