#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../entities/Trajet.h"

constexpr  int WIDTH = 1280, HEIGHT = 800;
constexpr  int WIDTH_Z = 32, HEIGHT_Z = 44;
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    SetTargetFPS(60);
    Trajet monsterTrajet = Trajet();
    Monster monster = Monster(5,0.0,{(float)monsterTrajet.getEnemyTrajet().at(0).x - (WIDTH_Z/2),(float)monsterTrajet.getEnemyTrajet().at(0).y - HEIGHT_Z,WIDTH_Z,HEIGHT_Z},*(new SpriteSheet(0,3, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png"))));
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(bg,0,0,WHITE);
            monster.setTimerFrame(monster.getTimerFrame()+GetFrameTime());
            monster.moveMonster(monsterTrajet);
            monster.drawEntity();
            monster.drawHitbox();
        if (monster.getTimerFrame() > 0.2f) {
            monster.nextSheet();
            monster.setTimerFrame(0);
        }
         EndDrawing();
    }
    return 0;
}
