//
// Created by CYTech Student on 2/27/2022.
//

#ifndef TOWERDEFENSE_PLAYER_H
#define TOWERDEFENSE_PLAYER_H

#include "raylib.h"


class Player {
    float initialHealth = 30;
    float health = 30;
    float money = 5;

public:
    Player(float health, float money);

    float getHealth() const;

    void setHealth(float health);

    float getMoney() const;

    void setMoney(float money);

    void drawHealth(char* msg);

    void drawMoney();

};


#endif //TOWERDEFENSE_PLAYER_H
