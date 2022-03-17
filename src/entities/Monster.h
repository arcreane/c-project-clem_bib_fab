//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_MONSTER_H
#define TOWERDEFENSE_MONSTER_H


#include "InfoEntities.h"
#include "../graphics/SpriteSheet.h"
#include "Trajet.h"
#include "Player.h"

class Monster : public InfoEntities {

    SpriteSheet spriteSheet;
    int monsterType;
    float health,initialHealth;
    bool finish = false;
    float money;
public:
    bool isFinish1() const;

    void setFinish(bool finish);

    int getMonsterType() const;

    void setMonsterType(int monsterType);

    float getHealth() const;

    void setHealth(float health);

    float getInitialHealth() const;

    void setInitialHealth(float initialHealth);

    void changeDirectionIfNeeded(Trajet trajet);

    void moveMonster(Trajet trajet);

    void nextSheet();

    void drawEntity();

    const SpriteSheet &getSpriteSheet() const;

    void setSpriteSheet(const SpriteSheet &spriteSheet);

    float getMoney() const;

    void setMoney(float money);

    Monster(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, float health, SpriteSheet &spriteSheet,
            int monsterType);
    Monster(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, float health, SpriteSheet &spriteSheet, int monsterType, float money);

    void drawHealthbox();
    bool isAlive();

    bool isFinish(Trajet trajet);

};


#endif //TOWERDEFENSE_MONSTER_H
