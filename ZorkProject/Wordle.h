//make only one wordle object exist at a time
#pragma once
#include <string>
#include <iostream>
class Wordle
{
public:
    Wordle(std::string wordToUse, int numAttempts);
    bool Play();
private:
    std::string word;
    std::string inputWord;
    int attempts;
    bool ParseWord(std::string wordToTest);
    bool Contains(char character, std::string word);
    bool CheckInput(std::string input);
};
