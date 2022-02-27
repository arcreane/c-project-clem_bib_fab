//
// Created by CYTech Student on 2/23/2022.
//

#include "Monster.h"

Monster::Monster(float damageDealt, float timerFrame,Rectangle &hitbox,  SpriteSheet &spriteSheet)
        : spriteSheet(spriteSheet),InfoEntities(damageDealt, timerFrame, hitbox) {
}

void Monster::changeDirectionIfNeeded(Trajet trajet) {
    std::vector<Vector2> allDir = trajet.getEnemyTrajet();
    std::vector<int> dir = trajet.getEnemyTrajetDir();
    for(int i = 0;i < allDir.size(); i++){
        if (CheckCollisionPointRec(allDir.at(i),this->getHitbox())){
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
                   {Monster::spriteSheet.getCurrentSheet() * Monster::spriteSheet.getWgap(),
                    Monster::spriteSheet.getDirection() * Monster::spriteSheet.getHgap(),
                    Monster::spriteSheet.getWgap(), Monster::spriteSheet.getHgap()}, {InfoEntities::getHitbox().x, InfoEntities::getHitbox().y + InfoEntities::getHitbox().height - Monster::spriteSheet.getHgap()}, WHITE);

}


