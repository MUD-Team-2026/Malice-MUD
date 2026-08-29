#include "Room.h"
#include "npc/NPC.h"   // ✅ 加上这一行

Room::Room() : Entity() {}

Room::Room(const string& id, const string& name, const string& desc)
    : Entity(id, name, desc) {}

void Room::addExit(const string& direction, Room* room) {
    exits[direction] = room;
}

Room* Room::getExit(const string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    }
    return nullptr;
}

bool Room::hasExit(const string& direction) const {
    return exits.find(direction) != exits.end();
}

string Room::getExitsDescription() const {
    if (exits.empty()) return "这里没有出口。";
    string result = "出口有：";
    for (auto& pair : exits) {
        result += pair.first + " ";
    }
    return result;
}

void Room::addNPC(NPC* npc) {
    npcs.push_back(npc);
}

vector<NPC*> Room::getNPCs() const {
    return npcs;
}

void Room::addItem(Item* item) {
    items.push_back(item);
}

vector<Item*> Room::getItems() const {
    return items;
}

string Room::getFullDescription() const {
    string result = "=== " + getName() + " ===\n";
    result += getDescription() + "\n\n";
    result += getExitsDescription() + "\n";

    if (!npcs.empty()) {
        result += "这里有 NPC：";
        for (auto npc : npcs) {
            result += npc->getName() + " ";
        }
        result += "\n";
    }

    return result;
}