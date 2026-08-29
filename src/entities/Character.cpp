#include "Character.h"

Character::Character() : Entity(), hp(100), maxHp(100), attack(10), defense(5) {}

Character::Character(const string& id, const string& name, const string& desc)
    : Entity(id, name, desc), hp(100), maxHp(100), attack(10), defense(5) {}

int Character::getHp() const { return hp; }
int Character::getMaxHp() const { return maxHp; }
int Character::getAttack() const { return attack; }
int Character::getDefense() const { return defense; }

void Character::setHp(int hp) { this->hp = hp; }
void Character::setMaxHp(int maxHp) { this->maxHp = maxHp; }
void Character::setAttack(int attack) { this->attack = attack; }
void Character::setDefense(int defense) { this->defense = defense; }

void Character::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

bool Character::isAlive() const {
    return hp > 0;
}