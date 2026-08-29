#include "SaveManager.h"
#include "Game.h"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

SaveManager::SaveManager() {
    saveDir = "saves/";
    if (!fs::exists(saveDir)) {
        fs::create_directory(saveDir);
    }
}

bool SaveManager::save(Game* game, const string& filename) {
    string fullPath = saveDir + filename;
    ofstream file(fullPath);
    
    if (!file.is_open()) {
        cout << "❌ 无法保存游戏" << endl;
        return false;
    }

    file << "# Malice-MUD Save File\n";
    file << "room:" << game->getCurrentRoom()->getId() << "\n";
    file << "week:" << game->getWeek() << "\n";
    file << "player_mental:" << game->getPlayerMental() << "\n";
    file << "suspect_mental:" << game->getSuspectMental() << "\n";
    file << "insight:" << game->getInsight() << "\n";
    file << "intuition:" << game->getIntuition() << "\n";
    file << "examine_count:" << game->getExamineCount() << "\n";

    file.close();
    cout << "✅ 游戏已保存" << endl;
    return true;
}

bool SaveManager::load(Game* game, const string& filename) {
    string fullPath = saveDir + filename;
    ifstream file(fullPath);
    
    if (!file.is_open()) {
        cout << "❌ 找不到存档" << endl;
        return false;
    }

    string line;
    string roomId;
    int week = 1, playerMental = 100, suspectMental = 100;
    int insight = 30, intuition = 30, examineCount = 0;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        size_t pos = line.find(':');
        if (pos == string::npos) continue;
        
        string key = line.substr(0, pos);
        string value = line.substr(pos + 1);
        
        if (key == "room") roomId = value;
        else if (key == "week") week = stoi(value);
        else if (key == "player_mental") playerMental = stoi(value);
        else if (key == "suspect_mental") suspectMental = stoi(value);
        else if (key == "insight") insight = stoi(value);
        else if (key == "intuition") intuition = stoi(value);
        else if (key == "examine_count") examineCount = stoi(value);
    }

    file.close();

    // 应用存档数据
    game->setWeek(week);
    game->setPlayerMental(playerMental);
    game->setSuspectMental(suspectMental);
    game->setInsight(insight);
    game->setIntuition(intuition);
    game->setExamineCount(examineCount);

    // 恢复房间位置
    // 通过房间ID获取房间指针（需要在Game中提供getRoomById方法）
    // 暂时用简单方式：遍历rooms

    cout << "✅ 游戏已读取" << endl;
    return true;
}

bool SaveManager::saveExists(const string& filename) {
    string fullPath = saveDir + filename;
    return fs::exists(fullPath);
}

vector<string> SaveManager::listSaves() {
    vector<string> files;
    if (!fs::exists(saveDir)) return files;
    for (const auto& entry : fs::directory_iterator(saveDir)) {
        if (entry.is_regular_file()) {
            files.push_back(entry.path().filename().string());
        }
    }
    return files;
}
