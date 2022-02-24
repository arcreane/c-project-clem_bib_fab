//
// Created by CYTech Student on 2/23/2022.
//

#include "Monster.h"


Monster::Monster(float x, float y, float with, float height, float damageDealt, float timerFrame, SpriteSheet &spriteSheet) : InfoEntities(x,
                                                                                                                     y,
                                                                                                                     with,
                                                                                                                     height,
                                                                                                                     damageDealt,
                                                                                                                     timerFrame),
                                                                                                        spriteSheet(
                                                                                                                spriteSheet) {}

 SpriteSheet &Monster::getSpriteSheet()  {
    return spriteSheet;
}

void Monster::setSpriteSheet(const SpriteSheet &spriteSheet) {
    Monster::spriteSheet = spriteSheet;
}

void Monster::nextSheet() {
    int  x = this->getSpriteSheet().getCurrentSheet();
    if (x + 1 > 2){
        this->getSpriteSheet().setCurrentSheet(0);
    }else{
        this->getSpriteSheet().setCurrentSheet(x + 1);
    }
}
