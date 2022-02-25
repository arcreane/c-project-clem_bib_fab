//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_INFOENTITIES_H
#define TOWERDEFENSE_INFOENTITIES_H


#include "raylib.h"
#include "../graphics/SpriteSheet.h"

class InfoEntities {
    float damageDealt;
    float timerFrame;
    Rectangle hitbox;
    SpriteSheet spriteSheet;
    int speed = 1;
    float health = 100;
    int monsterType;

public:

    InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox,  SpriteSheet &spriteSheet, int MonsterType);

    InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox,  SpriteSheet &spriteSheet, int MonsterType,
                 int speed);

    InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox, const SpriteSheet &spriteSheet,
                 int speed, float health, int monsterType);

    InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox, const SpriteSheet &spriteSheet,
                 float health, int monsterType);

    float getHealth() const;

    void setHealth(float health);

    void drawHitbox();

    void drawEntity();

    void nextSheet();

    float getDamageDealt() const;

    void setDamageDealt(float damageDealt);

    float getTimerFrame() const;

    void setTimerFrame(float timerFrame);

    const Rectangle &getHitbox() const;

    void setHitbox(const Rectangle &hitbox);

    SpriteSheet &getSpriteSheet() ;

    void setSpriteSheet(SpriteSheet &spriteSheet);

    void move();

    void drawHealthbox();

    bool isAlive();

};


#endif //TOWERDEFENSE_INFOENTITIES_H
