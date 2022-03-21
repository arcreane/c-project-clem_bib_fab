//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_TILEMAPMANAGER_H
#define TOWERDEFENSE_TILEMAPMANAGER_H


#include <vector>
#include "raylib.h"
#include "../entities/Tower.h"
#include "../listener/Inventory.h"
#include "../entities/Monster.h"

static constexpr  int WIDTH = 1600, HEIGHT = 800;
static constexpr  int WIDTH_GAME = 1280, HEIGHT_GAME = 800;
static constexpr  int WIDTH_Z = 32, HEIGHT_Z = 44;

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

    void drawTowers(std::vector<Tower> vector1);

    void aim(std::vector<Monster> &monsters, std::vector<Tower> &towersPlaced);

    bool isMonsterDetected(std::vector<Monster> monsters, Tower t);

    void placeTower(std::vector<Tower> &towersPlaced, Inventory &inventoryHandler, Player &player);
};


#endif //TOWERDEFENSE_TILEMAPMANAGER_H
