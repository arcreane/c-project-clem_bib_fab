#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"

constexpr  int WIDTH = 1280, HEIGHT = 800;
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    SetTargetFPS(60);
    Monster monster = Monster(5,0.0,{100,100,32,44},*(new SpriteSheet(0,1, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png"))));
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            monster.setTimerFrame(monster.getTimerFrame()+GetFrameTime());
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
