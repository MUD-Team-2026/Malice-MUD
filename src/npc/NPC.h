#ifndef NPC_H
#define NPC_H

#include "entities/Character.h"
#include <string>
using namespace std;

class NPC : public Character {
private:
    bool isHostile;

public:
    NPC();
    NPC(const string& id, const string& name, const string& desc);
    virtual ~NPC() = default;

    virtual string getFirstDialog() = 0;
    virtual string getDialog(const string& playerInput) = 0;

    void setHostile(bool hostile);
    bool getHostile() const;
};

#endif