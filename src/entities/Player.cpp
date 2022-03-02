//
// Created by CYTech Student on 2/27/2022.
//

#include <cstdio>
#include <iostream>
#include "Player.h"

Player::Player(float health, float money) : health(health), money(money) {
    this->initialHealth = health;
}

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

void Player::drawHealth(char* msg) {
    DrawText(TextSubtext(msg, 0, 20),0,0,20,BLACK);
    DrawRectangle(50,0,100,20,RED);
    DrawRectangle(50,0,(health/initialHealth)*100,20,GREEN);
}

void Player::drawMoney() {
    char msg[10];
    int argent = (int)this->getMoney();
    snprintf(msg,20,"Argent : %d",argent);
    DrawText(TextSubtext(msg, 0, 20),0,20,20,BLACK);
}
