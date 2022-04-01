#include "Wordle.h"
using namespace std;

//Constructor
Wordle::Wordle(std::string wordToUse,int maxAttempts) {
   word = wordToUse;
   attempts = maxAttempts;
}

bool Wordle::Play() {
   cout << "The Mages pen beckons you to write a word onto the rune!"<< endl;
    bool isSolved = false;
    string inputWord;
    int currentAttempts = 0;
    cout << "World lenght: " << word.length() << " you have " << attempts << " attempts" << std::endl;
    while (!isSolved) {
    cout << "Enter your word." << std::endl;
        do {
              cin >> inputWord;
        } while (!CheckInput(inputWord));

        isSolved = ParseWord(inputWord);
        currentAttempts++;
        if (currentAttempts > attempts) {
            cout << "Failed" << std::endl;
            return false;
        }
    }
    cout << "Success" << std::endl;
    return true;
}

bool Wordle::CheckInput(string input) {
    if (input.length() != word.length()) {
        cout << "Bad Input!" <<endl;
        return false;
    }
    return true;
}

bool Wordle::ParseWord(string wordToParse) {
    string line = "";

    for (int i = 0; i < wordToParse.length(); i++) {
        if (wordToParse[i] == word[i]) {
            line += "G";
            continue;
        }
        if (Contains(wordToParse[i],word)){
            line += "Y";
        }
        else {
            line += "B";
        }
    }

    cout << line <<endl;

    for (char character : line) {
        if (character != 'G') {
            return false;
        }
    }
    return true;

}

bool Wordle::Contains(char character, string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == character) {
            return true;
        }
    }
    return false;
}
