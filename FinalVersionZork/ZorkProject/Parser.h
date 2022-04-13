#ifndef PARSER_H
#define PARSER_H

#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
    CommandWords *commands;

public:
    Parser();
    Command* getCommand();
    void showCommands();
    ~Parser();
};

#endif // PARSER_H
