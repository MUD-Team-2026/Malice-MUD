#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include <string>
#include <vector>
using namespace std;

class Game;

class SaveManager {
private:
    string saveDir;

public:
    SaveManager();
    bool save(Game* game, const string& filename = "save.dat");
    bool load(Game* game, const string& filename = "save.dat");
    vector<string> listSaves();
    bool saveExists(const string& filename = "save.dat");
};

#endif
