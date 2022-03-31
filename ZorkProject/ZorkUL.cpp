#include <iostream>


using namespace std;
#include "ZorkUL.h"

int main(int argc, char** argv) {
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;
    a = new Room("Rendezvous");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
    b = new Room("East Rampart");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("West Rampart");
    d = new Room("South Rampart");
    e = new Room("Kings Keep");
    f = new Room("North Rampart");
    g = new Room("The Library");
    h = new Room("The Armoury");
    i = new Room("Mages Quaters");
    j = new Room("Sketchy Rope");
    j->addItem(new Item("GLIZZY", 1, 69));
    k = new Room("The Courtyard");

//             (N, E, S, W)
    a->setExits(j, NULL, NULL, NULL);
    b->setExits(NULL, NULL, e, k);
    c->setExits(h, k, NULL, NULL);
    d->setExits(k, e, NULL, i);
    e->setExits(NULL, NULL, NULL, NULL);
    f->setExits(NULL, g, k, NULL);
    g->setExits(NULL, NULL, b, NULL);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(c, NULL, NULL, NULL);
    j->setExits(d, NULL, NULL, NULL);
    k->setExits(NULL, NULL, NULL, NULL);


        currentRoom = a;

     arr.push_back(a);
     arr.push_back(b);
     arr.push_back(c);
     arr.push_back(d);
     arr.push_back(e);
     arr.push_back(f);
     arr.push_back(g);
     arr.push_back(h);
     arr.push_back(i);
     arr.push_back(j);
     arr.push_back(k);
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << " [The Armoury] --- [North Rampart] --- [The Library] " << endl;
        cout << "       |                  |                  |       " << endl;
        cout << "       |                  |                  |       " << endl;
        cout << "[West Rampart] --- [The Courtyard] --- [East Rampart]" << endl;
        cout << "       |                  |                  |       " << endl;
        cout << "       |                  |                  |       " << endl;
        cout << "[Mages Quaters] --- [South Rampart] --- [Kings Keep] " << endl;
        cout << "                          |                          " << endl;
        cout << "                    [Sketchy Rope]                   " << endl;
        cout << "                          |                          " << endl;
        cout << "                    [Rendezvous]                     " << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {


    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
        else
			return true; /**signal to quit*/

    } else if (commandWord.compare("teleport") == 0){
        if(command.hasSecondWord()){
            teleport(command.getSecondWord());
            cout << currentRoom->longDescription() << endl;
        }

    }
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

void ZorkUL::teleport(string roomDes){

    for(int i = 0; i<arr.size(); i++){
        if( arr.at(i)->shortDescription() == roomDes){
            currentRoom = arr.at(i);
            return;


        }
    }
}

