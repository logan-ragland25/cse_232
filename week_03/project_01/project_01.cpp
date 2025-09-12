#include <iostream>
#include <string>

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
        if (instanceOfWord < 0) {
            return std::string::npos;
        }
        if (AtListPosition(wordList, word, instanceOfWord)) {
            return instanceOfWord;
        }
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

int main()
{
    std::string word1 = "turtle";
    std::string word2 = "hare";
    
    // std::string list = "this,is,a,race,between,a,turtle,and,a,hare";
    // std::cout << GetFirstInList(list, word1, word2);
    
    std::string list = "sometimes,the,turtle,wins,even,though,everyone,expects,the,hare";
    std::cout << GetFirstInList(list, word1, word2);// == "turtle", "Check 2" << "\n";
    
    list = "but,usually,its,the,hare";
    std::cout << GetFirstInList(list, word1, word2); // == "hare", "Check 3" << "\n";
    
    list = "unless,the,turtle,races,itself";
    std::cout << GetFirstInList(list, word1, word2); // == "turtle", "Check 4" << "\n";
    
    list = "hair,is,not,a,valid,word";
    std::cout << GetFirstInList(list, word1, word2); // == "N/A", "Check 5" << "\n";

}
