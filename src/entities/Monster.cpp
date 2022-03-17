//
// Created by CYTech Student on 2/23/2022.
//

#include "Monster.h"

Monster::Monster(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, float health, SpriteSheet &spriteSheet, int monsterType)
        : spriteSheet(spriteSheet),monsterType(monsterType),health(health),initialHealth(health), InfoEntities(damageDealt, timerFrame, hitbox, speed) {
}

void Monster::drawHealthbox() {
    DrawRectangleLines(InfoEntities::getHitbox().x, InfoEntities::getHitbox().y-5, InfoEntities::getHitbox().width,5,RED);
    DrawRectangle(InfoEntities::getHitbox().x, InfoEntities::getHitbox().y-5,  (health/initialHealth)*(InfoEntities::getHitbox().width),5,GREEN);
}

bool Monster::isAlive() {
    if (this->getHealth() > 0) {
        return true;
    }
    return false;
}

void Monster::changeDirectionIfNeeded(Trajet trajet) {
    std::vector<Vector2> allDir = trajet.getEnemyTrajet();
    std::vector<int> dir = trajet.getEnemyTrajetDir();
    for(int i = 0;i < allDir.size(); i++){
        if (CheckCollisionPointRec(allDir.at(i),this->getHitbox())){
            health--;
            Monster::spriteSheet.setDirection(dir.at(i));
        }
    }
}

void Monster::moveMonster(Trajet trajet) {
    changeDirectionIfNeeded(trajet);
    switch ((int) this->spriteSheet.getDirection()) {
        case 0:
            this->getHitbox().y += (float) this->getSpeed();
            break;
        case 1:
            this->getHitbox().x -= (float) this->getSpeed();
            break;
        case 2:
            this->getHitbox().x += (float) this->getSpeed();
            break;
        case 3:
            this->getHitbox().y -= (float) this->getSpeed();
            break;
    }
}

void Monster::nextSheet() {
    int  x = Monster::spriteSheet.getCurrentSheet();
    if (x + 1 > 2){
        Monster::spriteSheet.setCurrentSheet(0);
    }else{
        Monster::spriteSheet.setCurrentSheet(x + 1);
    }
}

void Monster::drawEntity(){
    DrawTextureRec(Monster::spriteSheet.getSSheet(),
                   {Monster::spriteSheet.getCurrentSheet() * Monster::spriteSheet.getWgap() + monsterType,
                    Monster::spriteSheet.getDirection() * Monster::spriteSheet.getHgap(),
                    Monster::spriteSheet.getWgap(), Monster::spriteSheet.getHgap()},
                   {InfoEntities::getHitbox().x,
                    InfoEntities::getHitbox().y + InfoEntities::getHitbox().height -
                            Monster::spriteSheet.getHgap()}, WHITE);

}

int Monster::getMonsterType() const { return monsterType; }

void Monster::setMonsterType(int monsterType) { Monster::monsterType = monsterType; }

const SpriteSheet &Monster::getSpriteSheet() const { return spriteSheet; }

void Monster::setSpriteSheet(const SpriteSheet &spriteSheet) { Monster::spriteSheet = spriteSheet; }

float Monster::getHealth() const { return health; }

void Monster::setHealth(float health) { Monster::health = health; }

float Monster::getInitialHealth() const { return initialHealth; }

void Monster::setInitialHealth(float initialHealth) { Monster::initialHealth = initialHealth; }

bool Monster::isFinish(Trajet trajet) {
    std::vector<Vector2> allDir = trajet.getEnemyTrajet();
    if (CheckCollisionPointRec(allDir[3],this->getHitbox()) and !this->finish){
        this->setFinish(true);
        return true;
    }
    return false;
}

bool Monster::isFinish1() const {
    return finish;
}

void Monster::setFinish(bool finish) {
    Monster::finish = finish;
}




