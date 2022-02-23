//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_TOWER_H
#define TOWERDEFENSE_TOWER_H


#include "Projectile.h"
#include "InfoEntities.h"
#include <vector>
class Tower : InfoEntities{
    std::vector<Projectile> projectiles;
};


#endif //TOWERDEFENSE_TOWER_H
