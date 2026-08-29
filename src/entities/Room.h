#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class NPC;
class Item;

class Room : public Entity {
private:
    map<string, Room*> exits;
    vector<NPC*> npcs;
    vector<Item*> items;

public:
    Room();
    Room(const string& id, const string& name, const string& desc);

    void addExit(const string& direction, Room* room);
    Room* getExit(const string& direction) const;
    bool hasExit(const string& direction) const;
    string getExitsDescription() const;

    void addNPC(NPC* npc);
    vector<NPC*> getNPCs() const;

    void addItem(Item* item);
    vector<Item*> getItems() const;

    string getFullDescription() const;
};

#endif