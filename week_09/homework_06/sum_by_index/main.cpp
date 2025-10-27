#include <iostream>
#include <vector>

std::vector<int> SumByIndex(std::vector<std::vector<int>> const &vec) {
    std::vector<int> final = vec.at(0);

    for (unsigned int outer = 1; outer < vec.size(); outer++) {
        for (unsigned int inner = 0; inner < vec.at(outer).size(); inner++) {
                if (final.size() - 1 < inner) {
                    final.push_back(0);
                }
                final.at(inner) += vec.at(outer).at(inner);
        }
    }
    return final;
}