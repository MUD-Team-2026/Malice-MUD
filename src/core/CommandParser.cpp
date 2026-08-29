#include "CommandParser.h"
#include <sstream>

CommandParser::CommandParser() {
    // 初始化命令映射
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
}

Command CommandParser::parse(const string& input) {
    Command cmd;
    cmd.type = CommandType::UNKNOWN;
    cmd.arg = "";

    if (input.empty()) return cmd;

    istringstream iss(input);
    string word;
    iss >> word;

    // 查找命令
    auto it = cmdMap.find(word);
    if (it != cmdMap.end()) {
        cmd.type = it->second;
        // 获取参数（如果有）
        string arg;
        if (iss >> arg) {
            cmd.arg = arg;
        }
    }

    return cmd;
}

bool CommandParser::isValid(const string& input) {
    if (input.empty()) return false;
    string word;
    istringstream iss(input);
    iss >> word;
    return cmdMap.find(word) != cmdMap.end();
}

string CommandParser::getHelp() const {
    return "可用命令：\n"
           "  go <地点>      - 移动到指定地点\n"
           "  look           - 查看当前场景\n"
           "  examine <物品> - 仔细检查物品\n"
           "  talk <人名>    - 与NPC对话\n"
           "  combine <A>+<B>- 组合线索\n"
           "  think          - 整理思路\n"
           "  notebook       - 查看已收集线索\n"
           "  save           - 存档\n"
           "  load           - 读档\n"
           "  help           - 显示帮助\n"
           "  quit           - 退出游戏\n"
           "对质战斗命令：\n"
           "  质问 <线索名>  - 出示证据质问\n"
           "  沉思           - 恢复心理防线\n"
           "  威吓           - 削弱敌人气势";
}