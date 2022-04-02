#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include "Wordle.h"
using namespace std;

class ZorkUL {
private:
	Parser parser;
    vector<Room*> arr;
    Room *currentRoom;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    void teleport(string room);
    void use(string item);
    bool hasSword;
    bool hasPen;






public:
	ZorkUL();
	void play();
	string go(string direction);
    //public variable that stops player from progressing past mages tower without completing wordle
    bool roomDecipher;
    //public variable to determine whether the player is alive or dead
    bool isAlive;
    //destructor for zorkul variables
    ~ZorkUL();

};

#endif /*ZORKUL_H_*/
