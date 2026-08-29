#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
private:
    int insight;      // 洞察力
    int mental;       // 心理防线

public:
    Player();
    Player(const string& name);

    int getInsight() const;
    int getMental() const;
    void setInsight(int value);
    void setMental(int value);
};

#endif