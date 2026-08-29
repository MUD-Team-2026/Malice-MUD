#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

class NPC;
class Item;

// 房间ID常量
const string ROOM_POLICE = "police";
const string ROOM_STUDY = "study";
const string ROOM_LIVING = "living";
const string ROOM_SUSPECT_HOME = "suspect_home";
const string ROOM_OLD_SCHOOL = "old_school";
const string ROOM_OLD_HOUSE = "old_house";
const string ROOM_PHARMACY = "pharmacy";

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