#include <iostream>
#include<raylib.h>
#include "../entities/Tower.h"
#include "../entities/Monster.h"

constexpr  int WIDTH = 1280, HEIGHT = 800;
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    SetTargetFPS(60);
    Projectile projectile = Projectile(1.0,1,2,3,4,5);
    SpriteSheet s = new SpriteSheet(0, "../resources/zombie_n_skeleton2.png", 32, 64, 0);

    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextureRec(s.getSSheet(), {0,0,288,256},{0, 0}, WHITE);
        EndDrawing();
    }
    return 0;
}
