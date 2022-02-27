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
    int speed = 1;

public:

    InfoEntities(float damageDealt, float timerFrame, Rectangle &hitbox);

    InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox, int speed);

    InfoEntities();

    void drawHitbox();

    float getDamageDealt() const;

    void setDamageDealt(float damageDealt);

    float getTimerFrame() const;

    void setTimerFrame(float timerFrame);

   Rectangle &getHitbox();

    void setHitbox(Rectangle &hitbox);

    int getSpeed() const;

    void setSpeed(int speed);
};


#endif //TOWERDEFENSE_INFOENTITIES_H
