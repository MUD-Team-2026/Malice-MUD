#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <vector>
#include <map>
using namespace std;

// 命令类型枚举
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
    QUESTION,    // 对质：质问
    MEDITATE,    // 对质：沉思
    INTIMIDATE   // 对质：威吓
};

// 命令结构体
struct Command {
    CommandType type;
    string arg;  // 命令的参数，如 go 后面的地点名
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