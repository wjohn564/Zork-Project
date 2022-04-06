#include "Wordle.h"
using namespace std;

//Constructor
Wordle::Wordle(std::string wordToUse,int maxAttempts) {
   word = wordToUse;
   attempts = maxAttempts;
}

bool Wordle::Play() {
    //initial message
   cout << "The Mages pen beckons you to write a word onto the rune!"<< endl;
   cout << "The Rune has five highlighted square spaces to write on "<< endl;
   cout<<endl;
   cout<<"The mages journal beside the pen has a lot of erotic overly explained"<<endl;
   cout<< "scenarios.... but it also contains a clue!"<<endl;
   cout<<endl;
   cout<<"This person never leaves his room but always manages to have fun~"<<endl;
   //Set game to be unsolved
    bool isSolved = false;
    string inputWord;
    int currentAttempts = 0;
    cout << "Word lenght: " << word.length() << " you have " << attempts << " attempts" << std::endl;
    while (!isSolved) {
    cout << "Enter your word." << std::endl;
    //Use do to take in input before checking with while loop
        do {
              cin >> inputWord;
    //make sure word typed in is same length as wordle
        } while (!CheckInput(inputWord));

        isSolved = ParseWord(inputWord);
        currentAttempts++;
        if (currentAttempts > attempts) {
            cout << "You Failed to disenchant the door and you die from embarrassment...." << std::endl;
            return false;
        }
    }
    cout << "Success! The rune vanished, you may continue safely" << std::endl;
    return true;
}

//Function that checks if correct number of characters are inputted.
bool Wordle::CheckInput(string input) {
    if (input.length() != word.length()) {
        cout << "Bad Input!" <<endl;
        return false;
    }
    return true;
}

//Function that returns the colour of the letters
bool Wordle::ParseWord(string wordToParse) {
    string line = "";

//build up a String of the colours of the letter inputs depending on correctness
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

//Function that takes character and String that returns bool dependent on if character is in string for yellow inputs
bool Wordle::Contains(char character, string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == character) {
            return true;
        }
    }
    return false;
}
