#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../tile/TileMapManager.h"

constexpr  int WIDTH = 1600, HEIGHT = 800;
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    SetTargetFPS(60);
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    Texture2D inventory = LoadTexture("../resources/inventory.png");
    TileMapManager tileMapManager = TileMapManager("../resources/tower_defense.xml");
    Monster monster = Monster(5,0.0,{100,100,32,44},*(new SpriteSheet(0,1, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png"))));
   while(!WindowShouldClose()){
       BeginDrawing();
           ClearBackground(RAYWHITE);
           DrawTexture(bg,0,0,WHITE);
           DrawTexture(inventory,1280,0,WHITE);
           for (int i = 0; i < tileMapManager.getAvailablePlacesTower().size(); ++i) {
               Rectangle r  =  tileMapManager.getAvailablePlacesTower().at(i);
               DrawRectangleRec(r,RED);
           }
       EndDrawing();
   }
    return 0;
}
