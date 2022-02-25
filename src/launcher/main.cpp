#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../entities/Trajet.h"
#include "../tile/TileMapManager.h"

constexpr  int WIDTH = 1600, HEIGHT = 800;
constexpr  int WIDTH_Z = 32, HEIGHT_Z = 44;
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    SetTargetFPS(60);
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    Texture2D inventory = LoadTexture("../resources/inventory.png");
    Trajet monsterTrajet = Trajet();
    TileMapManager tileMapManager = TileMapManager("../resources/tower_defense.xml");
    Monster monster = Monster(5,0.0,{(float)monsterTrajet.getEnemyTrajet().at(0).x - (WIDTH_Z/2),(float)monsterTrajet.getEnemyTrajet().at(0).y - HEIGHT_Z,WIDTH_Z,HEIGHT_Z},*(new SpriteSheet(0,3, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png"))));
	while(!WindowShouldClose()){
       BeginDrawing();
           ClearBackground(RAYWHITE);
           DrawTexture(bg,0,0,WHITE);
           DrawTexture(inventory,1280,0,WHITE);
           monster.setTimerFrame(monster.getTimerFrame()+GetFrameTime());
            monster.moveMonster(monsterTrajet);
            monster.drawEntity();
            monster.drawHitbox();
	        if (monster.getTimerFrame() > 0.2f) {
	            monster.nextSheet();
	            monster.setTimerFrame(0);
	        }
           for (int i = 0; i < tileMapManager.getAvailablePlacesTower().size(); ++i) {
               Rectangle r  =  tileMapManager.getAvailablePlacesTower().at(i);
               DrawRectangleRec(r,RED);
           }
       EndDrawing();
   }
    return 0;
}
