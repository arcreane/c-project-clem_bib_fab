//
// Created by CYTech Student on 2/24/2022.
//

#include "Trajet.h"

#include <utility>

Trajet::Trajet() {
    this->enemyTrajet = {{192,800},{192,162-44},{1056+(32/2),162},{1056,800}};
    this->enemyTrajetDir = {3,2,0,0};
}

const std::vector<Vector2> &Trajet::getEnemyTrajet() const {
    return enemyTrajet;
}

const std::vector<int> &Trajet::getEnemyTrajetDir() const {
    return enemyTrajetDir;
}

