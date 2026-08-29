#ifndef GAME_H
#define GAME_H

#include "entities/Room.h"
#include "npc/Suspect.h"
#include "core/CommandParser.h"
#include "clues/Notebook.h"
#include "clues/Judge.h"
#include <map>
using namespace std;

class Game {
private:
    Room* currentRoom;
    map<string, Room*> rooms;
    Suspect* suspect;
    Notebook* notebook;
    Judge* judge;
    CommandParser parser;
    bool isRunning;

public:
    Game();
    ~Game();

    void init();
    void run();
    void processCommand(const string& input);
    void go(const string& direction);
    void look();
    void talk(const string& npcName);
    void examine(const string& itemName);
    void think();
    void showNotebook();
    void combine(const string& args);
    Room* getCurrentRoom() const;
};

#endif