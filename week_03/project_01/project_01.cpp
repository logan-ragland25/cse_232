#include <iostream>
#include <string>
#include <vector>

// Test if 'word' is a full entry in 'word_list' beginning as index 'pos'.
bool AtListPosition(std::string wordList, std::string word, size_t startPos) {
    int endPos{};
    std::string wordComparison{};

    // See if word is start of word
    if (startPos != 0 && wordList[startPos - 1] != ',') {
        return 0;
    }

    // Find first instance of a comma
    for (unsigned pos = startPos; pos < wordList.length(); pos++) {
        if (wordList[pos] == ',') {
            endPos = pos;
            break;
        }
    }

    // See if word is equal to the substring between the startPos and the End Pos
    if (wordList.substr(startPos, endPos - startPos) == word) {
        return 1;
    }
    else {
        return 0;
    }

    return 0;
}

size_t FindInList(std::string wordList, std::string word, size_t pos=0) {
    int instanceOfWord{}, searchLocationStart{};
    searchLocationStart = pos;

    while (true) {
        // Find where word starts
        instanceOfWord = wordList.find(word, searchLocationStart);

        // If word isn't found, return npos
        if (instanceOfWord < 0) {
            return std::string::npos;
        }

        // If word is found and is valid, return the location
        if (AtListPosition(wordList, word, instanceOfWord)) {
            return instanceOfWord;
        }

        // If word is found and not valid, find next instance
        else {
            searchLocationStart = instanceOfWord + 1;
        }
    }
    return std::string::npos;
}


std::string GetFirstInList(std::string wordList, std::string word1, std::string word2) {
    int word1Pos{}, word2Pos{};
    
    word1Pos = FindInList(wordList, word1);
    word2Pos = FindInList(wordList, word2);

    // Make sure words are not the only words in list
    if (word1 == wordList) {
        return word1;
    }
    if (word2 == wordList) {
        return word2;
    }

    // See if both words are found, and return whichever is found first
    if (word1Pos >= 0 && word2Pos >= 0) {
        if (word1Pos < word2Pos) {
            return word1;
        }
        else if (word1Pos > word2Pos) {
            return word2;
        }
    }

    //If neither are found or are equal, neither can be first
    else if ((word1Pos < 0 && word2Pos < 0) || word1Pos == word2Pos) {
        return "N/A";
    }

    // If one word is not found and the other is, the other word is returned
    else if (word1Pos < 0) {
        return word2;
    }
    else if (word2Pos < 0) {
        return word1;
    }

    return "N/A";
}

size_t CountInList(std::string wordList, std::string word) {
    int position{}, count{}, location{};

    // If the word is the same as the list, there can only be one of it
    if (word == wordList) {
        return 1;
    }

    // Find first instance of the word
    position = FindInList(wordList, word, 0);

    // While word is found
    while (position >= 0) {
        location = FindInList(wordList, word, position);
        
        // If word is not found, break loop
        if (location < 0) {
            break;
        }

        // If word is found, update counter and look for next instance
        count++;
        position = location + 1;
    }
    return count;
}

int main() {
    std::string word1{}, word2{}, wordList{}, firstFound{};
    int wordOneCount{}, wordTwoCount{};
    std::vector<std::string> listVector{};

    // std::cout << "Enter Word One: ";
    std::cin >> word1;

    // std::cout << "Enter Word Two: ";
    std::cin >> word2;

    // std::cout << "Enter List of Words: ";

    // Put all inputs into a vector
    while(std::cin >> wordList){
        listVector.push_back(wordList);
    }

    // Run the functions for each input
    for (std::string list : listVector) {
        wordOneCount = CountInList(list, word1);
        wordTwoCount = CountInList(list, word2);
        firstFound = GetFirstInList(list, word1, word2);
        std::cout << firstFound << " " << wordOneCount << " " << wordTwoCount << "\n";
    }
}
