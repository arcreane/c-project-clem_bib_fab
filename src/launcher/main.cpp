#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../entities/Trajet.h"
#include "../controller/Waves.h"
#include "../tile/TileMapManager.h"

constexpr  int WIDTH = 1280, HEIGHT = 800;
constexpr  int WIDTH_Z = 32, HEIGHT_Z = 44;
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    Texture2D inventory = LoadTexture("../resources/inventory.png");

    TileMapManager tileMapManager = TileMapManager("../resources/tower_defense.xml");

    SetTargetFPS(60);
    Trajet monsterTrajet = Trajet();

    Waves firstWave = Waves(5, 1, 3,2);
    std::vector<Monster> WaveMonsterList = firstWave.getListOfMonsters();

    std::vector<Monster> createdMonsters;
    float timer = 0.0f;
    int i = 0;

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(bg,0,0,WHITE);


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
           if (createdMonsters[j].getTimerFrame() > 0.2f) {
               createdMonsters[j].nextSheet();
               createdMonsters[j].setTimerFrame(0);
           }

       }

        for (int m = 0; m < tileMapManager.getAvailablePlacesTower().size(); ++m) {
            Rectangle r  =  tileMapManager.getAvailablePlacesTower().at(m);
            DrawRectangleRec(r,RED);
        }
         EndDrawing();
    }
    return 0;
}
