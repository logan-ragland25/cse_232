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

int main()
{
    std::string word_list="another,string,this,one,for,testing,beginning,and,end,words";

    
    std::cout << AtListPosition(word_list, "another", 0);
    // CHECK(!AtListPosition(word_list, "is", 4), "Off-by-one error");
    // CHECK(!AtListPosition(word_list, "is", 6), "Off-by-one error");
    // CHECK(!AtListPosition(word_list, "is", 20), "Right length, wrong word.");
    // CHECK(AtListPosition(word_list, "test", 10));
    // CHECK(AtListPosition(word_list, "list", 15));

}
