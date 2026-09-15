#include "CommandParser.h"
#include <sstream>
#include <vector>

CommandParser::CommandParser() {
    cmdMap["help"] = CommandType::HELP;
    cmdMap["quit"] = CommandType::QUIT;
    cmdMap["exit"] = CommandType::QUIT;
    cmdMap["go"] = CommandType::GO;
    cmdMap["look"] = CommandType::LOOK;
    cmdMap["examine"] = CommandType::EXAMINE;
    cmdMap["talk"] = CommandType::TALK;
    cmdMap["combine"] = CommandType::COMBINE;
    cmdMap["think"] = CommandType::THINK;
    cmdMap["notebook"] = CommandType::NOTEBOOK;
    cmdMap["save"] = CommandType::SAVE;
    cmdMap["load"] = CommandType::LOAD;
    cmdMap["质问"] = CommandType::QUESTION;
    cmdMap["沉思"] = CommandType::MEDITATE;
    cmdMap["威吓"] = CommandType::INTIMIDATE;
    cmdMap["對質"] = CommandType::CONFRONT;
    cmdMap["对质"] = CommandType::CONFRONT;
    cmdMap["对质"] = CommandType::CONFRONT;
    cmdMap["對質"] = CommandType::CONFRONT;
    cmdMap["对质"] = CommandType::CONFRONT;
    cmdMap["对质"] = CommandType::CONFRONT;
    cmdMap["report"] = CommandType::REPORT;
    cmdMap["map"] = CommandType::MAP;
    cmdMap["flee"] = CommandType::FLEE;      
    cmdMap["逃跑"] = CommandType::FLEE;      
    cmdMap["退出对质"] = CommandType::FLEE;  
}

Command CommandParser::parse(const string& input) {
    Command cmd;
    cmd.type = CommandType::UNKNOWN;
    cmd.arg = "";

    if (input.empty()) return cmd;

    size_t pos = input.find(' ');
    string word = input;
    string arg = "";

    if (pos != string::npos) {
        // ===== 有空格：正常分割 =====
        word = input.substr(0, pos);
        arg = input.substr(pos + 1);
        while (!arg.empty() && arg.front() == ' ') arg.erase(0, 1);
        while (!arg.empty() && arg.back() == ' ') arg.pop_back();
    }
    else {
        // ===== 没有空格：尝试匹配"指令+参数" =====
        // 按指令长度从长到短尝试匹配
        vector<string> commands = { "examine", "notebook", "confront", "combine",
                                   "report", "meditate", "intimidate", "talk",
                                   "look", "help", "quit", "exit", "save", "load",
                                   "think", "map", "go",
                                   "质问", "沉思", "威吓", "对质", "對質", "逃跑", "退出对质" };

        for (const string& command : commands) {
            if (input.substr(0, command.length()) == command && input.length() > command.length()) {
                word = command;
                arg = input.substr(command.length());
                // 去掉参数前面的空格（如果有）
                while (!arg.empty() && arg.front() == ' ') arg.erase(0, 1);
                break;
            }
        }
    }

    auto it = cmdMap.find(word);
    if (it != cmdMap.end()) {
        cmd.type = it->second;
        cmd.arg = arg;
    }

    return cmd;
}

bool CommandParser::isValid(const string& input) {
    if (input.empty()) return false;
    size_t pos = input.find(' ');
    string word = (pos != string::npos) ? input.substr(0, pos) : input;
    return cmdMap.find(word) != cmdMap.end();
}

string CommandParser::getHelp() const {
    return "可用命令：\n"
           "  go <地点>      - 移动到指定地点\n"
           "  look           - 查看当前场景\n"
           "  examine <物品> - 仔细检查物品\n"
           "  talk <人名>    - 与NPC对话\n"
          // "  combine <A>+<B>- 组合线索\n"
           "  think          - 整理思路\n"
           "  notebook       - 查看已收集线索\n"
           "  save           - 存档\n"
           "  load           - 读档\n"
           "  help           - 显示帮助\n"
           "  quit           - 退出游戏\n"
           "  report         - 提交结案报告\n"
           "  map            - 查看案件地图\n"
           "对质战斗命令：\n"
           "  质问 <线索名>  - 出示证据质问\n"
           "  沉思           - 恢复心理防线\n"
           "  威吓           - 削弱敌人气势\n"
           "  flee           - 退出对质";
}
