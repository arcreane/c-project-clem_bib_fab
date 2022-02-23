//
// Created by CYTech Student on 2/23/2022.
//

#include "Monster.h"

Monster::Monster(int x, int y, int with, int height, int damageDealt, SpriteSheet *spriteSheet) : InfoEntities(x,
                                                                                                               y,
                                                                                                               with,
                                                                                                               height,
                                                                                                               damageDealt),
                                                                                                  spriteSheet(spriteSheet) {}

const SpriteSheet &Monster::getSpriteSheet() const {
    return spriteSheet;
}
