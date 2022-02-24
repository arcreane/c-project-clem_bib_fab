//
// Created by CYTech Student on 2/23/2022.
//

#include "InfoEntities.h"

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

void InfoEntities::drawEntity(){
    DrawTextureRec(InfoEntities::spriteSheet.getSSheet(),
                   {InfoEntities::spriteSheet.getCurrentSheet() * InfoEntities::spriteSheet.getWgap(),
                    InfoEntities::spriteSheet.getDirection() * InfoEntities::spriteSheet.getHgap(),
                    InfoEntities::spriteSheet.getWgap(), InfoEntities::spriteSheet.getHgap()}, {InfoEntities::getHitbox().x, InfoEntities::getHitbox().y + InfoEntities::getHitbox().height - InfoEntities::spriteSheet.getHgap()}, WHITE);

}

InfoEntities::InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox, const SpriteSheet &spriteSheet)
        : damageDealt(damageDealt), timerFrame(timerFrame), hitbox(hitbox), spriteSheet(spriteSheet) {}

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

const SpriteSheet &InfoEntities::getSpriteSheet() const {
    return spriteSheet;
}

void InfoEntities::setSpriteSheet(const SpriteSheet &spriteSheet) {
    InfoEntities::spriteSheet = spriteSheet;
}



