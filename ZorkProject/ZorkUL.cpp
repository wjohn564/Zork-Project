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
    b = new Room("East Rampart");
    c = new Room("West Rampart");
    d = new Room("South Rampart");
    e = new Room("Kings Keep");
    f = new Room("North Rampart");
    g = new Room("The Library");
        g->addItem(new Item("book", 25, 50 ));
    h = new Room("The Armoury");
    h->addItem(new Item("kingslayer",100,10000));
    i = new Room("Mages Quaters");
    i->addItem(new Item("sus-pen", 1, 2500));
    j = new Room("Sketchy Rope");
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
    //Public variable to stop mages tower progression without wordle
    roomDecipher = false;
    //public variable to determine whether the player is alive or dead
    isAlive = true;
    hasPen = false;
    hasSword = false;
    hasBook = false;
    win = false;

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
    while (!finished && isAlive) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
        if(win) break;
    }if(win){
     cout<<   "You have slain the king and plundered the treasure behind his throne!"<<endl;
    cout<< "You have beaten the game"<<endl;
    }
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "Welcome to Zork, You have had enough of King Extontor's" << endl;
    cout << "lectures and have come to Assassinate him and steal his gold" << endl;
    cout << "Brown Thomas the kings jester feels the same way and has dropped a rope" << endl;
    cout << "that you may use to enter the castle from the south rampart" <<endl;
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
         else{
            //Added if statement
            if(command.getSecondWord() == "sus-pen" && currentRoom == arr[8]){
                Wordle rune = Wordle("gamer", 5);
                //Player returns boolean which determines whether you die or win and continue
                isAlive = rune.Play();
                //allows you to continue if you win
                roomDecipher = true;
                hasPen = true;
            }
             if(command.getSecondWord() == "kingslayer" && currentRoom == arr[7]){
                 hasSword = true;
             }
             if(command.getSecondWord() == "book" && currentRoom == arr[6]){
                 hasBook = true;
             }

        }

            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    //else if (commandWord.compare("put") == 0)
    //{


   // }
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
    //command to use item in inventory
    }else if(commandWord.compare("use") == 0){
        if (command.hasSecondWord()){
            if (command.getSecondWord()== "kingslayer" && hasSword && currentRoom == arr[4]){
                //makes sword third item for boss fight
               isAlive = boss.inputEncounter('c');
            }else if(command.getSecondWord()== "sus-pen" && hasPen && currentRoom == arr[4]){
                //makes pen first item for boss fight
               isAlive = boss.inputEncounter('a');
            }else if(command.getSecondWord()== "book" && hasBook){
                cout<< "To kill the King one must" <<endl;
                cout<<"1. Remove his rune"<<endl;
                cout<<"2. Distract him" <<endl;
                cout<<"3. Use the blade that removes those from the throne"<<endl;
              }



    }
        if(arr[4]){
            win = boss.sequenceComplete();
        }


}else if(commandWord.compare("inventory") == 0){
        if(hasSword)
            cout<< "kingslayer" <<endl;
        if(hasPen)
            cout<< "sus-pen";
        if(hasBook)
            cout<< "book";
        cout<<endl;

    }else if(commandWord.compare("dab") == 0){
        cout<< "YOU HIT AN EPIC DAB!!"<<endl;
   if(currentRoom == arr[4]){
   isAlive = boss.inputEncounter('b');
   }
    }
if(!isAlive && currentRoom == arr[4]){
    cout<< "The King slayes you viciously"<<endl;
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
    //if statement to stop progression without doing wordle in mages tower
    if(direction == "north" && currentRoom == arr[8] && !roomDecipher){
        cout<<"The Rune made you catch fire and implode..... You died" << endl;
        isAlive = false;
        return;
    }

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
        if (currentRoom == arr[8]){
            cout << "There is a Rune on the door that won't let you pass. you must decipher the mages password to continue." << endl;

        }
        //Not allowing you to leave boss fight
        if (currentRoom == arr[4]){
            boss = Encounter('a','b','c');
        }
        //if Statement that makes you fall to your death if you enter the courtyard from the ramparts
        if(currentRoom == arr[10]){
            isAlive = false;
            cout << "You fell 100 meters off the rampart and" <<endl;
            cout << "splatted on the ground to your death...." <<endl;
        }
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
//destructor for class
ZorkUL::~ZorkUL(){
    delete currentRoom;
}


