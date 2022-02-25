//
// Created by CYTech Student on 2/23/2022.
//

#include "InfoEntities.h"
#include <iostream>

void InfoEntities::drawHitbox() {
    DrawRectangleLines(InfoEntities::hitbox.x,InfoEntities::hitbox.y,InfoEntities::hitbox.width,InfoEntities::hitbox.height,RED);
}

void InfoEntities::nextSheet() {
    int  x = InfoEntities::spriteSheet.getCurrentSheet();
    if (x + 1 > 2){
        InfoEntities::spriteSheet.setCurrentSheet(0);
    }else{
        InfoEntities::spriteSheet.setCurrentSheet(x + 1);
    }
}

void InfoEntities::drawEntity() {
   /* int offset;
    switch (monsterType) {
        case 0:
            offset = 0;
            break;
        case 1:
            offset = 96;
            break;
        default:
            offset = 0;
            std::cout << "y'a peut etre un probleme chef" << std::endl;
    }*/
    DrawTextureRec(InfoEntities::spriteSheet.getSSheet(),
                   {InfoEntities::spriteSheet.getCurrentSheet() * InfoEntities::spriteSheet.getWgap() + monsterType,
                    InfoEntities::spriteSheet.getDirection() * InfoEntities::spriteSheet.getHgap(),
                    InfoEntities::spriteSheet.getWgap(), InfoEntities::spriteSheet.getHgap()},
                   {InfoEntities::getHitbox().x,
                    InfoEntities::getHitbox().y + InfoEntities::getHitbox().height -
                    InfoEntities::spriteSheet.getHgap()}, WHITE);
}

InfoEntities::InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox,  SpriteSheet &spriteSheet, int monsterType)
        : damageDealt(damageDealt), timerFrame(timerFrame), hitbox(hitbox), spriteSheet(spriteSheet), monsterType(monsterType) {}

float InfoEntities::getDamageDealt() const {
    return damageDealt;
}

void InfoEntities::setDamageDealt(float damageDealt) {
    InfoEntities::damageDealt = damageDealt;
}

float InfoEntities::getTimerFrame() const {
    return timerFrame;
}

void InfoEntities::setTimerFrame(float timerFrame) {
    InfoEntities::timerFrame = timerFrame;
}

const Rectangle &InfoEntities::getHitbox() const {
    return hitbox;
}

void InfoEntities::setHitbox(const Rectangle &hitbox) {
    InfoEntities::hitbox = hitbox;
}
SpriteSheet &InfoEntities::getSpriteSheet(){
    return spriteSheet;
}

void InfoEntities::setSpriteSheet(SpriteSheet &spriteSheet){
    InfoEntities::spriteSheet = spriteSheet;
}

void InfoEntities::move() {
    switch ((int)this->spriteSheet.getDirection()) {
        case 0:
            this->hitbox.y += (float)this->speed;
            break;
        case 1:
            this->hitbox.x -= (float)this->speed;
            break;
        case 2:
            this->hitbox.x += (float)this->speed;
            break;
        case 3:
            this->hitbox.y -= (float)this->speed;
            break;
    }
}

InfoEntities::InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox,  SpriteSheet &spriteSheet, int monsterType,
                           int speed) : damageDealt(damageDealt), timerFrame(timerFrame), hitbox(hitbox),
                                        spriteSheet(spriteSheet), speed(speed), monsterType(monsterType) {}

