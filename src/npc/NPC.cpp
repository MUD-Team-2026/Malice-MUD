#include "NPC.h"

NPC::NPC() : Character(), isHostile(false) {}

NPC::NPC(const string& id, const string& name, const string& desc)
    : Character(id, name, desc), isHostile(false) {}

void NPC::setHostile(bool hostile) {
    isHostile = hostile;
}

bool NPC::getHostile() const {
    return isHostile;
}