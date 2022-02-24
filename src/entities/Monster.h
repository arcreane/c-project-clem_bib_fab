//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_MONSTER_H
#define TOWERDEFENSE_MONSTER_H


#include "InfoEntities.h"
#include "../graphics/SpriteSheet.h"

class Monster : public InfoEntities {
    SpriteSheet spriteSheet;
public:

    Monster(float x, float y, float with, float height, float damageDealt,float timerFrame, SpriteSheet &spriteSheet);

    SpriteSheet &getSpriteSheet() ;

    void setSpriteSheet(const SpriteSheet &spriteSheet);

    void nextSheet();
};


#endif //TOWERDEFENSE_MONSTER_H
