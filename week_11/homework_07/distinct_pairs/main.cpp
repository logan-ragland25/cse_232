#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> findDistinctPairs (const std::vector<int>& vec, int target) {
    std::vector<std::vector<int>> pairs{};

    for (unsigned int pos = 0; pos < vec.size(); pos++) {
        for (unsigned int addingPos = 0; addingPos < vec.size(); addingPos++) {
            if (vec.at(pos) + vec.at(addingPos) == target) {
                std::vector<int> currentPairs = {vec.at(pos), vec.at(addingPos)};
                sort(currentPairs.begin(), currentPairs.end());

                bool found = false;

                for (unsigned int i = 0; i < pairs.size(); i++) {
                    if (pairs.at(i) == currentPairs) {
                        found = true;
                    }   
                }

                if (!found) {
                    pairs.push_back(currentPairs);
                }
            }
        }
    }
    sort(pairs.begin(), pairs.end());
    return pairs;
}

int main() {


    std::vector<int> nums = {1, 3, 2, 2, 4, 0, 5, 6, -1};
    int target = 5;
    std::vector<std::vector<int>> expected{{-1, 6}, {0, 5}, {1, 4}, {2,3}};
    std::vector<std::vector<int>> pairs = findDistinctPairs(nums, target);

    for (unsigned int i = 0; i < pairs.size(); i++) {
        for (unsigned int j = 0; j < pairs.at(i).size(); j++) {
            std::cout << pairs.at(i).at(j) << " ";
        }
        std::cout << "\n";
    }

    std::cout << (pairs == expected);

    return 1;
}