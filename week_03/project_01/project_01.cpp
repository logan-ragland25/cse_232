#include <iostream>
#include <string>

// Test if 'word' is a full entry in 'word_list' beginning as index 'pos'.
bool AtListPosition(std::string wordList, std::string word, size_t startingPos) {
    if (startingPos == 0) {
        if (wordList[startingPos + word.length()] != ',') {
            return 0;
        }
    }
    else {
        std::cout << (wordList[startingPos - 1] != ',');
        if (wordList[startingPos - 1] != ',') {
            return 0;
        }
        if (startingPos + word.length() == wordList.length()) {
            //std::cout << "test: " << wordList.substr(startingPos, word.length()) << " vs " << word;
            if (wordList.substr(startingPos, word.length()) == word) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (wordList[startingPos + word.length()] != ',') {
            return 0;
        }
    }
    return 0;
}

int FindInList(std::string word_list, std::string word, size_t pos=0) {
    // Declare Variables
    int location{};
    bool isFullWord{};

    // Get location of word
    location = word_list.find(word, pos);

    // See if location is found
    if (location < 0) {
        return -1;
    }
    if (location != 0) {
        isFullWord = AtListPosition(word_list, word, location);
        // If location is not the first value and is not preceded by a comma, it is not a full world
        while (!isFullWord) {
            location = word_list.find(word, location + 1);
            if (location < 0) {
                return -1;
            }
            isFullWord = AtListPosition(word_list, word, location);
        }
    }
    

    return location;
}

// Takes two strings and a word list.
// Returns the value of the string found first in the word list.
// Should return "N/A" if neither is in the word list.
std::string GetFirstInList(std::string word_list, std::string word1, std::string word2) {
    int word1Pos{}, word2Pos{};
    
    word1Pos = FindInList(word_list, word1);
    word2Pos = FindInList(word_list, word2);

    if (word1Pos >= 0 && word2Pos >= 0) {
        if (word1Pos < word2Pos) {
            return word1;
        }
        else if (word1Pos > word2Pos) {
            return word2;
        }
    }
    else if ((word1Pos < 0 && word2Pos < 0) || word1Pos == word2Pos) {
        return "N/A";
    }
    else if (word1Pos < 0) {
        return word2;
    }
    else if (word2Pos < 0) {
        return word1;
    }
    return "N/A";
}

// Takes a word_list and a word and counts the number of times that word
// is found in the list.
size_t CountInList(std::string word_list, std::string word) {
    int position{}, count{}, location{};

    position = FindInList(word_list, word, 0);
    while (position >= 0) {
        location = FindInList(word_list, word, position);
        if (location < 0) {
            break;
        }
        count++;
        position = location + 1;
        // std::cout << location << " " << position << "\n";
    }
    // std::cout << "Count of word " << word << ": " << count << "\n";
    return count;
}


// As inputs from std::cin, take in two words.  Then take in a series of comma-separated word_lists.
// For each word list provided, output which of the two words comes first, or "N/A" if neither is in
// the list.  Then output (on the same line) a count of how many times each word appeared.
//
// Example Input:
//   Kansas
//   Virginia
//   Virginia,Wyoming,Vermont
//   NewMexico,Kansas,Alabama,Virginia,NewYork,WestVirginia,Arkansas,Virginia,Utah,Virginia
//   Alaska
//
// Example Output:
//   Virginia 0 1
//   Kansas 1 3
//   N/A 0 0
//
// Note: The second output line has Virginia listed only 3 times, ignoring "WestVirginia"

int main()
{
    std::string word1{}, word2{}, wordList{}, firstFound{};
    int wordOneCount{}, wordTwoCount{};
    // int location{};

    wordList = "this,is,a,test,list,of,words";
    word1 = "Kansas";
    word2 = "Virginia";

    std::cout << AtListPosition(wordList, "is", 5) << "\n";
    // CountInList(wordList, word1);

    // wordList = "defeated,indefinitely,redefined";
    // word1 = "def";

    // std::cout << "Enter Word One: ";
    // std::cin >> word1;

    // std::cout << "Enter Word Two: ";
    // std::cin >> word2;

    // std::cout << "Enter List of Words: ";
    // std::cin >> wordList;

    // wordOneCount = CountInList(wordList, word1);
    // wordTwoCount = CountInList(wordList, word2);
    // firstFound = GetFirstInList(wordList, word1, word2);

    // std::cout << firstFound << " " << wordOneCount << " " << wordTwoCount << "\n";
}
