#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../entities/Trajet.h"
#include "../tile/TileMapManager.h"
#include "../entities/Player.h"
#include "../controller/Waves.h"


int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    Player p1 = Player(10,5) ;
    std::vector<Tower> towersPlaced;
    Inventory inventoryHandler = Inventory();
    SetTargetFPS(60);
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    Texture2D inventory = LoadTexture("../resources/inventory.png");
    Trajet monsterTrajet = Trajet();
    TileMapManager tileMapManager = TileMapManager("../resources/tower_defense.xml");
    Waves firstWave = Waves(1, 1, 1,0);
    std::vector<Monster> WaveMonsterList = firstWave.getListOfMonsters();

    std::vector<Monster> createdMonsters;
    float timer = 0.0f;
    int i = 0;
    while(!WindowShouldClose()){
       BeginDrawing();
           ClearBackground(RAYWHITE);
           DrawTexture(bg,0,0,WHITE);
           DrawTexture(inventory,1280,0, WHITE);
           inventoryHandler.DrawAllItems();
           inventoryHandler.checkIfneedToChangeSItem();
           tileMapManager.placeTower(towersPlaced, inventoryHandler);
           tileMapManager.drawTowers(towersPlaced);
           timer += GetFrameTime();
           if (timer > 0.5f && i<= WaveMonsterList.size()) {
               createdMonsters.push_back(WaveMonsterList[i]);
               i++;
               timer = 0.0f;
           }
           for (int j = 0; j < createdMonsters.size(); ++j) {
               createdMonsters[j].setTimerFrame(createdMonsters[j].getTimerFrame()+GetFrameTime());
               createdMonsters[j].moveMonster(monsterTrajet);
               createdMonsters[j].drawEntity();
               createdMonsters[j].drawHitbox();
               createdMonsters[j].drawHealthbox();
               if (createdMonsters[j].getTimerFrame() > 0.2f) {
                   createdMonsters[j].nextSheet();
                   createdMonsters[j].setTimerFrame(0);
               }
               if (!createdMonsters[j].isAlive()){
                   createdMonsters.erase(createdMonsters.begin()+j);
               }
           }
           tileMapManager.aim(createdMonsters,towersPlaced);
       EndDrawing();
   }
    return 0;
}
