//
// Created by CYTech Student on 2/23/2022.
//

#include "Monster.h"

Monster::Monster(float damageDealt, float timerFrame, const Rectangle &hitbox,  SpriteSheet &spriteSheet,int monsterType)
        : InfoEntities(damageDealt, timerFrame, hitbox, spriteSheet, monsterType) {
}

void Monster::changeDirectionIfNeeded(Trajet trajet) {
    std::vector<Vector2> allDir = trajet.getEnemyTrajet();
    std::vector<int> dir = trajet.getEnemyTrajetDir();
    for(int i = 0;i < allDir.size(); i++){
        if (CheckCollisionPointRec(allDir.at(i),this->getHitbox())){
            Monster::getSpriteSheet().setDirection(dir.at(i));
        }
    }
}

void Monster::moveMonster(Trajet trajet) {
    changeDirectionIfNeeded(trajet);
    InfoEntities::move();
}


