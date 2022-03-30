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
#include "../controller/Waves.h"


static constexpr  int WIDTH = 1600, HEIGHT = 800;
static constexpr  int WIDTH_GAME = 1280, HEIGHT_GAME = 800;
static constexpr  int WIDTH_Z = 32, HEIGHT_Z = 44;
static constexpr  int RATIO = 64/2;
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

    void monsterHandling(std::vector<Monster> &createdMonsters, std::vector<Monster> &WaveMonsterList, Trajet monsterTrajet,
                    int &wavesOccuring, int &textFramesCounter, int j, Player &p1);

    void launch();

    void drawEndGameScreen(Texture2D tex,int posx);

    void endGame(Player p1, int wavesOccuring, std::vector<Waves> allWaves);

    void
    wavesHandling(std::vector<Monster> &createdMonsters, std::vector<Monster> &WaveMonsterList,
                  std::vector<Waves> allWaves,
                  Trajet monsterTrajet, int &wavesOccuring, int &textFramesCounter, int &i, Player &p1, float &timer, char message[15]);

    void
    drawAll(Player &p1, Inventory &inventoryHandler, std::vector<Tower> &towersPlaced, Texture2D inventory, Texture2D bg,
            char *msgHealth);
};


#endif //TOWERDEFENSE_TILEMAPMANAGER_H
