#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../entities/Trajet.h"
#include "../tile/TileMapManager.h"
#include "../listener/Inventory.h"
#include "../entities/Player.h"

int fun(int a ){
    return  a +1;
}
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
    Rectangle rec = {(float)monsterTrajet.getEnemyTrajet().at(0).x - (WIDTH_Z/2),(float)monsterTrajet.getEnemyTrajet().at(0).y - HEIGHT_Z,WIDTH_Z,HEIGHT_Z};
    Monster monster = Monster(5,0.0,rec,*(new SpriteSheet(0,3, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png"))));
	while(!WindowShouldClose()){
       BeginDrawing();
           ClearBackground(RAYWHITE);
           DrawTexture(bg,0,0,WHITE);
           DrawTexture(inventory,1280,0, WHITE);
           inventoryHandler.DrawAllItems();
           inventoryHandler.checkIfneedToChangeSItem();
           tileMapManager.placeTower(towersPlaced, inventoryHandler);
           tileMapManager.drawTowers(towersPlaced);
       EndDrawing();
   }

    return 0;
}
