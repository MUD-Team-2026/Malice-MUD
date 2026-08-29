#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

class Character : public Entity {
private:
    int hp;
    int maxHp;
    int attack;
    int defense;

public:
    Character();
    Character(const string& id, const string& name, const string& desc);

    int getHp() const;
    int getMaxHp() const;
    int getAttack() const;
    int getDefense() const;

    void setHp(int hp);
    void setMaxHp(int maxHp);
    void setAttack(int attack);
    void setDefense(int defense);

    void takeDamage(int damage);
    bool isAlive() const;
};

#endif