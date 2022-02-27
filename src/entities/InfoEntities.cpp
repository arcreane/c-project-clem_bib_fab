//
// Created by CYTech Student on 2/23/2022.
//

#include <iostream>
#include "InfoEntities.h"

void InfoEntities::drawHitbox() {
    DrawRectangleLines(InfoEntities::hitbox.x,InfoEntities::hitbox.y,InfoEntities::hitbox.width,InfoEntities::hitbox.height,RED);
}

InfoEntities::InfoEntities(float damageDealt, float timerFrame,  Rectangle &hitbox)
        : damageDealt(damageDealt), timerFrame(timerFrame), hitbox(hitbox) {}
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

Rectangle &InfoEntities::getHitbox()  {
    return hitbox;
}

void InfoEntities::setHitbox( Rectangle &hitbox) {
    InfoEntities::hitbox = hitbox;
}

InfoEntities::InfoEntities() {}

int InfoEntities::getSpeed() const {
    return speed;
}

void InfoEntities::setSpeed(int speed) {
    InfoEntities::speed = speed;
}


InfoEntities::InfoEntities(float damageDealt, float timerFrame, const Rectangle &hitbox, int speed)
        : damageDealt(damageDealt), timerFrame(timerFrame), hitbox(hitbox), speed(speed) {}




