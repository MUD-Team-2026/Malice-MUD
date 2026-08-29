#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <map>
using namespace std;

enum class CommandType {
    UNKNOWN,
    HELP,
    QUIT,
    GO,
    LOOK,
    EXAMINE,
    TALK,
    COMBINE,
    THINK,
    NOTEBOOK,
    SAVE,
    LOAD,
    QUESTION,
    MEDITATE,
    INTIMIDATE,
    REPORT,
    MAP
};

struct Command {
    CommandType type;
    string arg;
};

class CommandParser {
private:
    map<string, CommandType> cmdMap;

public:
    CommandParser();
    Command parse(const string& input);
    bool isValid(const string& input);
    string getHelp() const;
};

#endif
