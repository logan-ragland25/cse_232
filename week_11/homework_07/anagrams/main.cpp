#include "anagrams.hpp"

#include <iostream>
#include <vector>
#include <string>

int main() {
    
    std::vector<std::string> input{"bat","eat","tea","ate","arc","tab","car","sparks"};
    std::vector<std::vector<std::string>> expected{{"arc","car"},{"ate","eat","tea"},{"bat","tab"},{"sparks"}};
    std::vector<std::vector<std::string>> result = groupSortedAnagrams(input);

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result.at(i).size(); j++) {
            std::cout << result.at(i).at(j) << " ";
        }
        std::cout << "\n";
    }

    std::cout << (groupSortedAnagrams(input) == expected);

    return 1;
}