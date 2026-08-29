#include "Clue.h"

Clue::Clue() : Entity(), isKey(false), location("") {}

Clue::Clue(const string& id, const string& name, const string& desc,
           bool key, const string& loc)
    : Entity(id, name, desc), isKey(key), location(loc) {}

bool Clue::getIsKey() const { return isKey; }
string Clue::getLocation() const { return location; }
vector<string> Clue::getCombineTargets() const { return combineTargets; }

void Clue::setIsKey(bool key) { isKey = key; }
void Clue::setLocation(const string& loc) { location = loc; }

void Clue::addCombineTarget(const string& targetId) {
    combineTargets.push_back(targetId);
}

bool Clue::canCombineWith(const string& otherId) const {
    for (const string& target : combineTargets) {
        if (target == otherId) return true;
    }
    return false;
}