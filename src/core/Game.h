#ifndef GAME_H
#define GAME_H

#include "entities/Room.h"
#include "npc/Suspect.h"
#include "core/CommandParser.h"
#include <map>
using namespace std;

class Game {
private:
    Room* currentRoom;
    map<string, Room*> rooms;
    Suspect* suspect;
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
    Room* getCurrentRoom() const;
};

#endif