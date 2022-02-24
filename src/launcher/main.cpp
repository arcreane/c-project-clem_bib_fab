#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"

constexpr  int WIDTH = 1280, HEIGHT = 800;
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    SetTargetFPS(60);
    SpriteSheet s = SpriteSheet(0,0, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png"));
    Monster monster = Monster(0,0,3,4,5,0.0,s);
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            monster.setTimerFrame(monster.getTimerFrame()+GetFrameTime());
        DrawTextureRec(monster.getSpriteSheet().getSSheet(),
                       {monster.getSpriteSheet().getCurrentSheet() * monster.getSpriteSheet().getWgap(),
                        monster.getSpriteSheet().getDirection() * monster.getSpriteSheet().getHgap(),
                        monster.getSpriteSheet().getWgap(), monster.getSpriteSheet().getHgap()}, {0, 0}, WHITE);
        if (monster.getTimerFrame() > 0.2f) {
            monster.nextSheet();
            monster.setTimerFrame(0);
        }
         EndDrawing();
    }
    return 0;
}
