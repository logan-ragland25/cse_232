#include "anagrams.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

std::vector<std::vector<std::string>> groupSortedAnagrams(std::vector<std::string> &input) {
    std::vector<std::string> comparisons{};
    std::vector<std::vector<std::string>> output{};
    for (unsigned int inputPos = 0; inputPos < input.size(); inputPos++) {
        bool found{0};

        for (unsigned int outputPos = 0; outputPos < output.size(); outputPos++) {
            std::string sortedInput = input.at(inputPos);
            sort(sortedInput.begin(), sortedInput.end());

            std::string sortedOutput = output.at(outputPos).at(0);
            sort(sortedOutput.begin(), sortedOutput.end());
            
            if (sortedInput == sortedOutput) {
                output.at(outputPos).push_back(input.at(inputPos));
                found = 1;
            }
        }

        if (!found) {
            output.push_back(std::vector<std::string>{input.at(inputPos)});
        }
    }

    for (unsigned int pos = 0; pos < output.size(); pos++) {
        sort(output.at(pos).begin(), output.at(pos).end());
    }

    sort(output.begin(), output.end());

    return output;
}