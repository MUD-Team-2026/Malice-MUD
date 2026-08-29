#include "Room.h"
#include "npc/NPC.h"

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

    // 添加可检查物品提示
    if (getId() == "study") {
        result += "你可以检查：纸镇、樱花\n";
    } else if (getId() == "suspect_home") {
        result += "你可以检查：手稿、打字机\n";
    } else if (getId() == "living") {
        result += "你可以检查：录影带\n";
    } else if (getId() == "pharmacy") {
        result += "你可以检查：毒药（或山埃）\n";
    } else if (getId() == "old_school") {
        result += "你可以检查：毕业册\n";
    } else if (getId() == "old_house") {
        result += "你可以检查：信件\n";
    }

    return result;
}
