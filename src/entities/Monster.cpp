//
// Created by CYTech Student on 2/23/2022.
//

#include "Monster.h"

Monster::Monster(float damageDealt, float timerFrame, const Rectangle &hitbox, const SpriteSheet &spriteSheet)
        : InfoEntities(damageDealt, timerFrame, hitbox, spriteSheet) {}
