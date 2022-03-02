#include <iostream>
#include<raylib.h>
#include <string>
#include <charconv>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../entities/Trajet.h"
#include "../tile/TileMapManager.h"
#include "../entities/Player.h"
#include "../controller/Waves.h"


int main() {
    InitWindow(WIDTH,HEIGHT,"tower defense");
    Player p1 = Player(25,5) ;
    std::vector<Tower> towersPlaced;
    Inventory inventoryHandler = Inventory();
    SetTargetFPS(60);
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    Texture2D inventory = LoadTexture("../resources/inventory.png");
    Trajet monsterTrajet = Trajet();
    TileMapManager tileMapManager = TileMapManager("../resources/tower_defense.xml");

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
    char message[15] = "WAVE %d" ;
    char msgHealth[10] = "Vie : ";

    while(!WindowShouldClose()){
       BeginDrawing();
           ClearBackground(RAYWHITE);
           DrawTexture(bg,0,0,WHITE);
           DrawTexture(inventory,1280,0, WHITE);
           inventoryHandler.DrawAllItems();
           inventoryHandler.checkIfneedToChangeSItem();
           tileMapManager.placeTower(towersPlaced, inventoryHandler);
           tileMapManager.drawTowers(towersPlaced);
           p1.drawHealth(msgHealth);
           p1.drawMoney();
           timer += GetFrameTime();
           timertest += GetFrameTime();
           textFramesCounter++;

           if(WaveMonsterList.empty() && wavesOccuring < 3){
               WaveMonsterList = allWaves[wavesOccuring].getListOfMonsters();
               i=0;
               //affiche toujours le meme numero de vague, correctif en cours
               snprintf(message, 20, message , wavesOccuring+1);
           }
            DrawText(TextSubtext(message, 0, textFramesCounter/14), 580, 550, 33, WHITE);
            if (timer > 0.5f && i< WaveMonsterList.size()) {
                   createdMonsters.push_back(WaveMonsterList[i]);
                   i++;
                   timer = 0.0f;
            }
            for (int j = 0; j < createdMonsters.size(); ++j) {
               createdMonsters[j].setTimerFrame(createdMonsters[j].getTimerFrame()+GetFrameTime());
               createdMonsters[j].moveMonster(monsterTrajet);
               createdMonsters[j].drawEntity();
               createdMonsters[j].drawHitbox();
               createdMonsters[j].drawHealthbox();
               if (createdMonsters[j].getTimerFrame() > 0.2f) {
                   createdMonsters[j].nextSheet();
                   createdMonsters[j].setTimerFrame(0);
               }
               //damage du monstre si il arrive au bout
               if (createdMonsters[j].isFinish(monsterTrajet)){
                   p1.setHealth(p1.getHealth()-createdMonsters[j].getDamageDealt());
               }
               if (!createdMonsters[j].isAlive()){
                   createdMonsters.erase(createdMonsters.begin()+j);
                   //gain en fonction du type de monstre
                   switch (createdMonsters[j].getMonsterType()) {
                       case 0:
                           p1.setMoney(p1.getMoney()+1);
                           break;
                       case 96:
                           p1.setMoney(p1.getMoney()+2);
                           break;
                       default:
                           break;
                   }
                   if(createdMonsters.empty()){
                       WaveMonsterList.erase(WaveMonsterList.begin(), WaveMonsterList.end());
                       wavesOccuring+=1;
                       textFramesCounter = 0;
                   }
                   //TODO: comprendre pourquoi on a j = 5 à un moment dans la premiere vague (hint: ca semble etre au point de passage de départ);
                   /*
                   std::cout<<"nombre de zombies dans la vague: "<<createdMonsters.size()<<std::endl;
                    */
               }

           }
       EndDrawing();
   }
    return 0;
}
