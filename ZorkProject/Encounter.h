#pragma once
#include <string>
#include <iostream>

using namespace std;

class Encounter
{
public:
    Encounter(char char1 = 'a', char char2 = 'b', char char3 = 'c');
    bool inputEncounter(char input);
    bool sequenceComplete();

private:
    char key[3];
    char userSeq[3];
    int currentPos;
};
