//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_PROJECTILE_H
#define TOWERDEFENSE_PROJECTILE_H


#include "InfoEntities.h"

class Projectile : public InfoEntities{
    float speed;
public:
    Projectile(float speed,int x, int y, int with, int height, int damageDealt):InfoEntities(x,  y,  with,  height,  damageDealt){
        this->speed = speed;
    };

};


#endif //TOWERDEFENSE_PROJECTILE_H
