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
    int instanceOfWord{}, location{};
    location = pos;

    while (true) {
        instanceOfWord = wordList.find(word, location);
        if (AtListPosition(wordList, word, instanceOfWord)) {
            return instanceOfWord;
        }
        else {
            location = instanceOfWord + 1;
        }
    }
}

int main()
{
    std::string word_list="A,list,of,words,to,use,for,testing";
    std::cout << FindInList(word_list, "A");
    // CHECK(FindInList(word_list, "list") == 2u);
    // CHECK(FindInList(word_list, "of") == 7u);
    // CHECK(FindInList(word_list, "words") == 10u);
    // CHECK(FindInList(word_list, "to") == 16u);
    // CHECK(FindInList(word_list, "use") == 19u);
    // CHECK(FindInList(word_list, "for") == 23u);
    // CHECK(FindInList(word_list, "testing") == 27u);

}
