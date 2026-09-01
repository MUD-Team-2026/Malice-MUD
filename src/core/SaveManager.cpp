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

    // 保存所有游戏状态
    file << "# Malice-MUD Save File\n";
    file << "room:" << game->getCurrentRoom()->getId() << "\n";
    file << "week:" << game->getWeek() << "\n";
    file << "player_mental:" << game->getPlayerMental() << "\n";
    file << "suspect_mental:" << game->getSuspectMental() << "\n";
    file << "insight:" << game->getInsight() << "\n";
    file << "intuition:" << game->getIntuition() << "\n";
    file << "examine_count:" << game->getExamineCount() << "\n";
    file << "chose_continue:" << game->getChoseContinue() << "\n";
    file << "trap_triggered:" << game->getTrapTriggered() << "\n";
    file << "found_surface1:" << game->getFoundSurface1() << "\n";
    file << "found_surface2:" << game->getFoundSurface2() << "\n";
    file << "game_over:" << game->getGameOver() << "\n";
    file << "has_submitted:" << game->getHasSubmittedReport() << "\n";

    // 保存 Notebook 中的线索
    Notebook* notebook = game->getNotebook();
    if (notebook) {
        vector<Clue*> clues = notebook->getAllClues();
        file << "clue_count:" << clues.size() << "\n";
        for (Clue* clue : clues) {
            file << "clue:" << clue->getId() << "|" << clue->getName() << "|" 
                 << clue->getDescription() << "|" << clue->getIsKey() << "|" 
                 << clue->getLocation() << "\n";
        }
    }

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
    bool choseContinue = false, trapTriggered = false;
    bool foundSurface1 = false, foundSurface2 = false;
    bool gameOver = false, hasSubmitted = false;
    vector<tuple<string, string, string, bool, string>> loadedClues;

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
        else if (key == "chose_continue") choseContinue = (value == "1");
        else if (key == "trap_triggered") trapTriggered = (value == "1");
        else if (key == "found_surface1") foundSurface1 = (value == "1");
        else if (key == "found_surface2") foundSurface2 = (value == "1");
        else if (key == "game_over") gameOver = (value == "1");
        else if (key == "has_submitted") hasSubmitted = (value == "1");
        else if (key == "clue") {
            // 解析线索: id|name|description|isKey|location
            // 簡單處理：用 | 分割
            vector<string> parts;
            size_t start = 0, end = 0;
            while ((end = value.find('|', start)) != string::npos) {
                parts.push_back(value.substr(start, end - start));
                start = end + 1;
            }
            parts.push_back(value.substr(start));
            if (parts.size() >= 5) {
                loadedClues.push_back(make_tuple(parts[0], parts[1], parts[2], 
                                                  parts[3] == "1", parts[4]));
            }
        }
    }

    file.close();

    // 應用存檔數據到 Game
    game->setWeek(week);
    game->setPlayerMental(playerMental);
    game->setSuspectMental(suspectMental);
    game->setInsight(insight);
    game->setIntuition(intuition);
    game->setExamineCount(examineCount);
    game->setChoseContinue(choseContinue);
    game->setTrapTriggered(trapTriggered);
    game->setFoundSurface1(foundSurface1);
    game->setFoundSurface2(foundSurface2);
    game->setGameOver(gameOver);
    game->setHasSubmittedReport(hasSubmitted);

    // 恢復房間位置
    game->moveToRoom(roomId);

    // 恢復 Notebook 中的線索
    Notebook* notebook = game->getNotebook();
    if (notebook) {
        // 清空 Notebook
        notebook->clear();
        for (auto& t : loadedClues) {
            Clue* clue = new Clue(get<0>(t), get<1>(t), get<2>(t), get<3>(t), get<4>(t));
            notebook->addClue(clue);
        }
    }

    cout << "✅ 游戏已读取" << endl;
    return true;
}
