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

public:

    InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox, const SpriteSheet &spriteSheet);

    void drawHitbox();

    void drawEntity();

    void nextSheet();

    float getDamageDealt() const;

    void setDamageDealt(float damageDealt);

    float getTimerFrame() const;

    void setTimerFrame(float timerFrame);

    const Rectangle &getHitbox() const;

    void setHitbox(const Rectangle &hitbox);

    const SpriteSheet &getSpriteSheet() const;

    void setSpriteSheet(const SpriteSheet &spriteSheet);
};


#endif //TOWERDEFENSE_INFOENTITIES_H
