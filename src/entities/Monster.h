//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_MONSTER_H
#define TOWERDEFENSE_MONSTER_H


#include "InfoEntities.h"
#include "../graphics/SpriteSheet.h"
#include "Trajet.h"

class Monster : public InfoEntities {

    SpriteSheet spriteSheet;
    int monsterType;
    float health,initialHealth;
public:
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

    Monster(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, float health, SpriteSheet &spriteSheet,
            int monsterType);

    void drawHealthbox();
    bool isAlive();

};


#endif //TOWERDEFENSE_MONSTER_H
