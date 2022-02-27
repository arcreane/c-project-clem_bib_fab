//
// Created by CYTech Student on 2/23/2022.
//

#include "InfoEntities.h"

void InfoEntities::drawHitbox() {
    DrawRectangleLines(InfoEntities::hitbox.x,InfoEntities::hitbox.y,InfoEntities::hitbox.width,InfoEntities::hitbox.height,RED);
}

InfoEntities::InfoEntities(float damageDealt, float timerFrame,  Rectangle &hitbox)
        : damageDealt(damageDealt), timerFrame(timerFrame), hitbox(hitbox) {}
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
float InfoEntities::getHealth() const {
    return health;
}

void InfoEntities::setHealth(float health) {
    InfoEntities::health = health;
}

void InfoEntities::drawHealthbox() {
    float health = this->getHealth();
    DrawRectangleLines(this->hitbox.x, this->hitbox.y-5, this->hitbox.width,5,RED);
    DrawRectangle(this->hitbox.x, this->hitbox.y-5, (this->hitbox.width*health)/100,5,GREEN);
}

bool InfoEntities::isAlive() {
    if (this->getHealth() > 0) {
        return true;
    }
    return false;

}


