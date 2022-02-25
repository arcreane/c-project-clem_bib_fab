//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_TILEMAPMANAGER_H
#define TOWERDEFENSE_TILEMAPMANAGER_H


#include <vector>
#include "raylib.h"

class TileMapManager {
    std::vector<Rectangle> placesTower;
    std::vector<Rectangle> availablePlacesTower;
    std::vector<int> idsPlaces = {313,129,405};
    const float WIDTH_TILES = 32;
    const float HEIGHT_TILES = 32;
public:
    TileMapManager(const char* file);
    TileMapManager(std::vector<Rectangle> &placesTower, std::vector<Rectangle> &availablePlacesTower);

    std::vector<Rectangle> &getPlacesTower() ;

    void setPlacesTower( std::vector<Rectangle> &placesTower);

    std::vector<Rectangle> &getAvailablePlacesTower() ;

    void setAvailablePlacesTower( std::vector<Rectangle> &availablePlacesTower);
};


#endif //TOWERDEFENSE_TILEMAPMANAGER_H
