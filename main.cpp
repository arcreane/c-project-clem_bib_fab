/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>
#include "Enemy.h"
using namespace std;

#define Enemy_Amount 1

Enemy enemy[Enemy_Amount] = { *new Enemy()};
Rectangle FrameRect = *new Rectangle();

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;


    FrameRect.x = 0;
    FrameRect.y = 0;
    FrameRect.width = 55;
    FrameRect.height = 97;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Image background = LoadImage("../resources/bg.png");
    ImageResize(&background, 800, 450);

    Texture2D texture = LoadTextureFromImage(background);

    UnloadImage(background); // Unload image from RAM

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //-------------------------------------------------------------------------------------

    for (int i = 0; i < Enemy_Amount; i++){
        enemy[i].Enemy::setEnemyTrajetSens(0);
        enemy[i].Enemy::setEnemyTrajetCount(0);
        enemy[i].Enemy::setEnemyPosition((Vector2){0,150});
        enemy[i].Enemy::setEnemyFrameRec(FrameRect);
        enemy[i].Enemy::setActive(true);
        enemy[i].Enemy::setEnemyFramesCounter(0);
        enemy[i].Enemy::setEnemyFramesSpeed(6);
        enemy[i].Enemy::setEnemyCurrentFrame(0);


    }


    Texture2D Enemy = LoadTexture("../resources/sprite.png");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        for (int i = 0; i<Enemy_Amount;i++){
            if (enemy[i].Enemy::isActive()){


                if (enemy[i].Enemy::getEnemyPosition().x == enemy[i].Enemy::getEnemyTrajet()[0] and enemy[i].Enemy::getEnemyTrajetCount() == 0){
                    enemy[i].Enemy::setEnemyTrajetSens(1);
                    enemy[i].Enemy::setEnemyTrajetCount(1);
                }
                else if (enemy[i].Enemy::getEnemyPosition().y == enemy[i].Enemy::getEnemyTrajet()[1] and enemy[i].Enemy::getEnemyTrajetCount() == 1){
                    enemy[i].Enemy::setEnemyTrajetSens(0);
                    enemy[i].Enemy::setEnemyTrajetCount(2);
                }
                else if (enemy[i].Enemy::getEnemyPosition().x == enemy[i].Enemy::getEnemyTrajet()[2] and enemy[i].Enemy::getEnemyTrajetCount() == 2){
                    enemy[i].Enemy::setEnemyTrajetSens(2);
                    enemy[i].Enemy::setEnemyTrajetCount(3);
                }
                else if (enemy[i].Enemy::getEnemyPosition().y == enemy[i].Enemy::getEnemyTrajet()[3] and enemy[i].Enemy::getEnemyTrajetCount() == 3){
                    enemy[i].Enemy::setEnemyTrajetSens(0);
                    enemy[i].Enemy::setEnemyTrajetCount(4);
                }
                else if (enemy[i].Enemy::getEnemyPosition().x == enemy[i].Enemy::getEnemyTrajet()[4] and enemy[i].Enemy::getEnemyTrajetCount() == 4){
                    enemy[i].Enemy::setEnemyTrajetSens(1);
                    enemy[i].Enemy::setEnemyTrajetCount(5);
                }
                else if (enemy[i].Enemy::getEnemyPosition().y == enemy[i].Enemy::getEnemyTrajet()[5] and enemy[i].Enemy::getEnemyTrajetCount() == 5){
                    enemy[i].Enemy::setEnemyTrajetSens(0);
                }

                switch (enemy[i].Enemy::getEnemyTrajetSens()) {
                    case 0: //droite
//                        enemy[i].Enemy::setEnemyPosition(Enemy::getEnemyPosition()).x += 1;
                        Vector2 vec1;
                        vec1.x = enemy[i].Enemy::getEnemyPosition().x + 1;
                        vec1.y = enemy[i].Enemy::getEnemyPosition().y;
                        enemy[i].Enemy::setEnemyPosition(vec1);
                        break;
                    case 1: //haut
                        Vector2 vec2;
                        vec2.x = enemy[i].Enemy::getEnemyPosition().x;
                        vec2.y = enemy[i].Enemy::getEnemyPosition().y - 1;
                        enemy[i].Enemy::setEnemyPosition(vec2);
                        break;
                    case 2: //bas
                        Vector2 vec3;
                        vec3.x = enemy[i].Enemy::getEnemyPosition().x;
                        vec3.y = enemy[i].Enemy::getEnemyPosition().y + 1;
                        enemy[i].Enemy::setEnemyPosition(vec3);
                        break;
                }



                enemy[i].Enemy::setEnemyFramesCounter(enemy[i].Enemy::getEnemyFramesCounter() + 1);

                if (enemy[i].Enemy::getEnemyFramesCounter() >= (60/enemy[i].Enemy::getEnemyFramesSpeed())){
                    enemy[i].Enemy::setEnemyFramesCounter(0);
                    enemy[i].Enemy::setEnemyCurrentFrame(enemy[i].Enemy::getEnemyCurrentFrame() + 1);

                    if (enemy[i].Enemy::getEnemyCurrentFrame() > 5){
                        enemy[i].Enemy::setEnemyCurrentFrame(0);
                    }

                    Rectangle rec;
                    rec.x = (float)enemy[i].Enemy::getEnemyCurrentFrame()*(float)Enemy.width/6;
                    rec.y = 0;
                    rec.width = enemy[i].Enemy::getEnemyFrameRec().width;
                    rec.height = enemy[i].Enemy::getEnemyFrameRec().height;
                    enemy[i].Enemy::setEnemyFrameRec(rec);

                }
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(texture, 0, 0, WHITE);

        DrawTextureRec(Enemy, enemy[0].Enemy::getEnemyFrameRec(), enemy[0].Enemy::getEnemyPosition(), WHITE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
