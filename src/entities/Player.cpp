#include "Player.h"

Player::Player() : Character(), insight(50), mental(100) {}

Player::Player(const string& name) : Character(), insight(50), mental(100) {
    setName(name);
}

int Player::getInsight() const { return insight; }
int Player::getMental() const { return mental; }

void Player::setInsight(int value) { insight = value; }
void Player::setMental(int value) { mental = value; }