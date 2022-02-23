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
    Monster(int x, int y, int with, int height, int damageDealt, SpriteSheet *spriteSheet);

    const SpriteSheet &getSpriteSheet() const;
};


#endif //TOWERDEFENSE_MONSTER_H
