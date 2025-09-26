#include <iostream>
#include <vector>

// Divides words into vectors
std::vector<std::string> InsertStringIntoVector (std::string input) {
    std::vector<std::string> wordList{};
    int newStartPos{0};

    // Loop through each character in string
    for (unsigned int pos = 0; pos < input.length(); pos ++) {
        
        // See if character is last character
        bool finalChar = (pos == input.length() - 1);

        // If space is found or it is the last character, it is the end of a word; add that word to the vector
        if (input.at(pos) == ' ' || pos == input.length() - 1) {
            // Make newStartPos + 1 from space position to prevent starting with space
            // Add bool finalCharake to sure to include last character
            wordList.push_back(input.substr(newStartPos, pos - newStartPos + finalChar));
            newStartPos = pos + 1;
        }
    }
    return wordList;
}

// Breaks a word into parts, starting from the end and moving inwards
std::vector<std::string> BreakIntoParts (std::string word) {
    std::vector<std::string> BrokenUpWord{};

    // Loop through word, adding each ending to the vector
    // ex logan would be [n, an, gan, ogan, logan]
    for (unsigned int pos = 0; pos < word.length(); pos++) {
        BrokenUpWord.push_back(word.substr(word.length() - 1 - pos, pos + 1));
    }

    return BrokenUpWord;
}

// Find how many character the end of word one has with the start of end two
int NumberOfCharactersOverlap (std::string wordOne, std::string wordTwo) {
    int overlappedCharacters {}; 

    // Break Word One into Parts
    std::vector<std::string> overlapList = BreakIntoParts(wordOne);

    // Loop through all endings to word
    for (unsigned int overlapWordNumber = 0; overlapWordNumber < overlapList.size(); overlapWordNumber++) {

        // If there is overlap, add to the amount of overlapped characters
        if (0 + wordTwo.find(overlapList.at(overlapWordNumber)) == 0) {
            overlappedCharacters = overlapWordNumber + 1; 
        }
    }
    return overlappedCharacters;
}

int main () {
    std::string input{};

    // Run code while input is recieved
    while (getline(std::cin, input)) {

        std::vector wordList = InsertStringIntoVector(input);
        int overlappedCharacterCount{};
        std::string finalSentence{};

        // Loop through each word in the broken up word list
        for (unsigned int pos = 0; pos < wordList.size() - 1; pos++) {

            // Find how many characters the end of the current word shares with the start of the next
            overlappedCharacterCount = NumberOfCharactersOverlap(wordList.at(pos), wordList.at(pos + 1));

            if (overlappedCharacterCount > 0) {
                // If there is overlap, it must be removed
                // Add the current word to the start of the next, removing the overlap so it is not doubled
                // Then erase the first word, as they are now one word. With one less length, pos must be decreased
                wordList.at(pos + 1) = wordList.at(pos) + wordList.at(pos + 1).substr(overlappedCharacterCount, wordList.at(pos + 1).length() - overlappedCharacterCount);
                wordList.erase(wordList.begin() + pos);
                pos--;
            }
        }
        
        // Loop through each word after alteration, adding it back into the sentence
        for (unsigned int pos = 0; pos < wordList.size() - 1; pos++) {
            finalSentence.append(wordList.at(pos) + " ");
        }
        finalSentence.append(wordList.at(wordList.size() - 1));

        std::cout << finalSentence << "\n";
    }
    
    return 0;
}