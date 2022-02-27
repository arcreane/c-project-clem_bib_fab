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
public:

    Monster(float damageDealt, float timerFrame, Rectangle &hitbox,  SpriteSheet &spriteSheet);


    void changeDirectionIfNeeded(Trajet trajet);

    void moveMonster(Trajet trajet);

    void nextSheet();

    void drawEntity();
};


#endif //TOWERDEFENSE_MONSTER_H
