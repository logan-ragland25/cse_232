#include <iostream>
#include <string>

// Test if 'word' is a full entry in 'word_list' beginning as index 'pos'.
bool AtListPosition(std::string wordList, std::string word, size_t startingPos) {
    int endingPos{};
    std::string fullWord{};

    // if (startingPos != 0 && word_list[startingPos - 1] != ',') {
    //     return 0;
    // }
    // for (unsigned pos = startingPos; pos < word_list.length(); pos++ ) {
    //     if (word_list[pos] == ',') {
    //         endingPos = pos;
    //         break;
    //     }
    // }

    // fullWord = word_list.substr(startingPos, endingPos - startingPos);

    // return (fullWord == word);
    //std::cout << wordList[startingPos - 1] << " : " << wordList[startingPos + word.length()] << " : " << startingPos + word.length() << "\n";
    if (startingPos == 0) {
        if (wordList[startingPos + word.length()] != ',') {
            return 0;
        }
    }
    else {
        if (wordList[startingPos - 1] != ',' || wordList[startingPos + word.length()] != ',') {
            return 0;
        }
    }
    return 1;
}

// Inputs are:
//   word_list - a string that contains a list of comma-separated words.
//   word - a string that contains to word to search for in the list.
//   pos - an optional size_t containing the position to start the search
//         (start at zero if no pos argument is provided)
// Return:
//   The index where 'word' was found as a full entry in word_list -or-
//   std::string::npos if word is not found
//
// Note, must match FULL word.  So "def" would be matched in "abc,def,ghijk,l" or in
// "def,456,ghi,789,jkl", but NOT in "defeated,indefinitely,redefined"
size_t FindInList(std::string word_list, std::string word, size_t pos=0) {
    // Declare Variables
    int location{};
    bool fullWord{};

    // Get location of word
    location = word_list.find(word, pos);
    
    // See if location is found
    if (location < 0) {
        return std::string::npos;
    }
    if (location != 0) {
        // If location is not the first value and is not preceded by a comma, it is not a full world
        while (!fullWord) {
            location = word_list.find(word, location + 1);
            if (location < 0) {
                return std::string::npos;
            }
            fullWord = AtListPosition(word_list, word, location);
        }
    }
    

    return location;
}

// Takes two strings and a word list.
// Returns the value of the string found first in the word list.
// Should return "N/A" if neither is in the word list.
std::string GetFirstInList(std::string word_list, std::string word1, std::string word2) {
    return {};
}

// Takes a word_list and a word and counts the number of times that word
// is found in the list.
size_t CountInList(std::string word_list, std::string word) {
    return {};
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
    std::string word1, word2, wordList {};
    int wordOneCount, wordTwoCount, location {};

    wordList = "NewMexico,Kansas,Alabama,Virginia,NewYork,WestVirginia,Arkansas,Virginia,Utah,Virginia";
    word1 = "Virginia";
    
    // wordList = "defeated,indefinitely,redefined";
    // word1 = "def";

    // std::cout << "Enter Word One: ";
    // std::cin >> word1;

    // std::cout << "Enter Word Two: ";
    // std::cin >> word2;

    // std::cout << "Enter List of Words: ";
    // std::cin >> wordList;

    // location = FindInList(wordList, word1, 40);
    // std::cout << "Function Output: " << location << ", " << wordList.substr(location, word1.length());
    // wordOneCount = CountInList(wordList, word1);
    // wordTwoCount = CountInList(wordList, word2);

    //std::cout << AtListPosition(wordList, word1, 11) << "\n";
}
