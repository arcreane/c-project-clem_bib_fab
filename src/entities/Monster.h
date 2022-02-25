//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_MONSTER_H
#define TOWERDEFENSE_MONSTER_H


#include "InfoEntities.h"
#include "../graphics/SpriteSheet.h"
#include "Trajet.h"

class Monster : public InfoEntities {

public:

    Monster(float damageDealt, float timerFrame, const Rectangle &hitbox,  SpriteSheet &spriteSheet, int monsterType);

    void changeDirectionIfNeeded(Trajet trajet);

    void moveMonster(Trajet trajet);



};


#endif //TOWERDEFENSE_MONSTER_H
