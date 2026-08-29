#ifndef SUSPECT_H
#define SUSPECT_H

#include "NPC.h"

class Suspect : public NPC {
private:
    int despairLevel;
    bool hasConfessed;
    bool isLying;
    int attackCooldown;

public:
    Suspect();
    Suspect(const string& id, const string& name, const string& desc);

    string getFirstDialog() override;
    string getDialog(const string& playerInput) override;

    int getDespairLevel() const;
    void increaseDespair(int amount);
    void confess();
    bool getHasConfessed() const;

    void setLying(bool lying);
    bool getIsLying() const;

    string getLieVersion();
    string getTruthVersion();

    string getAttackType();
    int calculateDamage();
    bool canUseLastLie();
    void resetAttackCooldown();
};

#endif
