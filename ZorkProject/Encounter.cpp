#include "Encounter.h"

Encounter::Encounter(char char1, char char2, char char3)
{
  cout << "The king has appeared before you !!" << endl;
    key[0] = char1;
    key[1] = char2;
    key[2] = char3;
    currentPos = 0;
    userSeq[0] = '0';
    userSeq[1] = '1';
    userSeq[2] = '2';
}

bool Encounter::inputEncounter(char input)
{
    userSeq[currentPos] = input;
    currentPos++;

    for (int i = 0; i < currentPos; i++) {
        if (userSeq[i] == key[i]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

bool Encounter::sequenceComplete() {
    if (userSeq[0] == key[0] && userSeq[1] == key[1] && userSeq[2] == key[2]) {
        return true;
    }
    else {
        return false;
    }
}
