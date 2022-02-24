//
// Created by CYTech Student on 2/24/2022.
//

#ifndef TOWERDEFENSE_TRAJET_H
#define TOWERDEFENSE_TRAJET_H


#include <vector>
#include <list>
#include "raylib.h"

class Trajet {
    std::vector<Vector2> enemyTrajet; //{192,162,1056,800};
    std::vector<int> enemyTrajetDir;
public:
    Trajet();

    const std::vector<Vector2> &getEnemyTrajet() const;

    const std::vector<int> &getEnemyTrajetDir() const;
};


#endif //TOWERDEFENSE_TRAJET_H
