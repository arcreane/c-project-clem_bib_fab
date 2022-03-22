#include<raylib.h>
#include <string>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../tile/TileMapManager.h"
#include "../controller/Waves.h"

void drawEndGameScreen(Texture2D tex,int posx);
int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    Player p1 = Player(25,5) ;
    std::vector<Tower> towersPlaced;
    Inventory inventoryHandler = Inventory();
    SetTargetFPS(60);
    Texture2D gg = LoadTexture("../resources/GG.png");
    Texture2D gameOver = LoadTexture("../resources/game_over.png");
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    Texture2D inventory = LoadTexture("../resources/inventory.png");
    Trajet monsterTrajet = Trajet();
    TileMapManager tileMapManager = TileMapManager("../resources/tower_defense.xml");

    //création des waves
    std::vector<Waves> allWaves;
    allWaves.emplace_back(Waves( 1, 3,2));
    allWaves.emplace_back(Waves( 2, 6,4));
    allWaves.emplace_back(Waves( 3, 6,14));

    std::vector<Monster> WaveMonsterList;
    std::vector<Monster> createdMonsters;

    float timertest = 0.0f;
    float timer = 0.0f;
    int i = 0;
    int wavesOccuring = 0;
    int textFramesCounter = 0;
    char messageToFormat[15] = "WAVE %d" ;
    char message[15];
    char msgHealth[10] = "Vie : ";

    while(!WindowShouldClose() && p1.getHealth() > 0 && allWaves.size() > wavesOccuring){
       BeginDrawing();
           ClearBackground(RAYWHITE);
           DrawTexture(bg,0,0,WHITE);
           DrawTexture(inventory,1280,0, WHITE);
           inventoryHandler.DrawAllItems();
           inventoryHandler.checkIfneedToChangenDisplay();
           tileMapManager.placeTower(towersPlaced, inventoryHandler, p1);
           tileMapManager.drawTowers(towersPlaced);
           p1.drawHealth(msgHealth);
           p1.drawMoney();
           timer += GetFrameTime();
           timertest += GetFrameTime();
           textFramesCounter++;

           //display le numéro de wave en cours
           if(WaveMonsterList.empty() && wavesOccuring < 3){
               WaveMonsterList = allWaves[wavesOccuring].getListOfMonsters();
               i=0;
               snprintf(message, 15, messageToFormat , wavesOccuring);
           }
            DrawText(TextSubtext(message, 0, textFramesCounter/14), 580, 550, 33, WHITE);
            if (timer > 0.5f && i< WaveMonsterList.size()) {
                   createdMonsters.push_back(WaveMonsterList[i]);
                   i++;
                   timer = 0.0f;
            }

            for (int j = 0; j < createdMonsters.size(); ++j) {
                createdMonsters[j].setTimerFrame(createdMonsters[j].getTimerFrame() + GetFrameTime());
                createdMonsters[j].moveMonster(monsterTrajet);
                createdMonsters[j].drawEntity();
                createdMonsters[j].drawHitbox();
                createdMonsters[j].drawHealthbox();
                if (createdMonsters[j].getTimerFrame() > 0.2f) {
                    createdMonsters[j].nextSheet();
                    createdMonsters[j].setTimerFrame(0);
                }
                //damage du monstre si il arrive au bout
                if (createdMonsters[j].isFinish(monsterTrajet)) {
                    p1.setHealth(p1.getHealth() - createdMonsters[j].getDamageDealt());
                    //createdMonsters[j].setHealth(0);
                }
                //si le monstre meurt
                if (!createdMonsters[j].isAlive()) {
                    p1.setMoney(p1.getMoney() + createdMonsters[j].getMoney());
                    createdMonsters.erase(createdMonsters.begin() + j);
                    //si les monstres de la waves sont mort, on passe à la wave suivante
                    if (createdMonsters.empty()) {
                        WaveMonsterList.erase(WaveMonsterList.begin(), WaveMonsterList.end());
                        wavesOccuring += 1;
                        textFramesCounter = 0;
                    }
                }

            }
            //tir les missiles téléguidés
           tileMapManager.aim(createdMonsters,towersPlaced);
       EndDrawing();
   }
    //End Game
    if (p1.getHealth() <= 0 ) { drawEndGameScreen(gameOver,WIDTH / 4); }
    else if(allWaves.size() <= wavesOccuring){
        drawEndGameScreen(gg,0);
    }
    return 0;
}

void drawEndGameScreen(Texture2D tex,int posx){
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(tex, posx, 0, WHITE);
        EndDrawing();
    }
}

