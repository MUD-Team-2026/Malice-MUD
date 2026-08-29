#ifndef CLUE_H
#define CLUE_H

#include "entities/Entity.h"
#include <vector>
#include <string>
using namespace std;

class Clue : public Entity {
private:
    bool isKey;
    string location;
    vector<string> combineTargets;

public:
    Clue();
    Clue(const string& id, const string& name, const string& desc,
         bool key = false, const string& loc = "");

    bool getIsKey() const;
    string getLocation() const;
    vector<string> getCombineTargets() const;

    void setIsKey(bool key);
    void setLocation(const string& loc);
    void addCombineTarget(const string& targetId);
    bool canCombineWith(const string& otherId) const;
};

#endif