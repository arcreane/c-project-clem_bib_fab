//
// Created by CYTech Student on 2/27/2022.
//

#include "Player.h"

Player::Player(float health, float money) : health(health), money(money) {}

float Player::getHealth() const {
    return health;
}

void Player::setHealth(float health) {
    Player::health = health;
}

float Player::getMoney() const {
    return money;
}

void Player::setMoney(float money) {
    Player::money = money;
}
