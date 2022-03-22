//
// Created by CYTech Student on 2/23/2022.
//

#include "TileMapManager.h"
#include "../entities/Tower.h"
#include "../listener/Inventory.h"
#include "../entities/Monster.h"
#include <fstream>
using std::ifstream;
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include "../controller/Waves.h"


TileMapManager::TileMapManager(std::vector<Rectangle> &placesTower, std::vector<Rectangle> &availablePlacesTower) {

}

std::vector<Rectangle> &TileMapManager::getPlacesTower() {
    return TileMapManager::placesTower;
}

void TileMapManager::setPlacesTower(std::vector<Rectangle> &placesTower) {

}

std::vector<Rectangle> &TileMapManager::getAvailablePlacesTower() {
    return TileMapManager::availablePlacesTower;
}

void TileMapManager::setAvailablePlacesTower(std::vector<Rectangle> &availablePlacesTower) {

}

TileMapManager::TileMapManager(const char* file) {
    int id;
    float x=-1,y=-1;
    std::ifstream tileMapsXml;
    std::string line;
    std::string s = "0123456789";
    tileMapsXml.open(file);
    if (tileMapsXml.is_open()){
        while(tileMapsXml){
            std::getline(tileMapsXml,line);
            if(s.find(line[0]) != std::string::npos ){
                y++;
                //si le carractère de fin est une virgule on la supprime
                if (s.find(line[line.size() - 1]) == std::string::npos) {
                    line.pop_back();
                }
                std::stringstream ss( line);
                while(ss.good()){
                    x++;
                    std::string substr;
                    getline( ss, substr, ',' );
                    id = std::stoi(substr);
                    if(std::count(this->idsPlaces.begin(), this->idsPlaces.end(), id)){
                            this->placesTower.push_back({x*WIDTH_TILES,y*HEIGHT_TILES,WIDTH_TILES * 2,HEIGHT_TILES * 2});
                            this->availablePlacesTower.push_back({x*WIDTH_TILES,y*HEIGHT_TILES,WIDTH_TILES * 2,HEIGHT_TILES * 2});
                    }
                }
                x=-1;
            }else{
                y=-1;
            }
        }
    }else{
        std::cout << "Something went wrong while opening " << file;
    }
}


//place la selected tower à l'endroit selectionné
void TileMapManager::placeTower(std::vector<Tower> &towersPlaced, Inventory &inventoryHandler,Player &player) {
    bool notPlacedYet = true;
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mvector = GetMousePosition();
        for (int i = 0; i < placesTower.size(); ++i) {
            Rectangle place = placesTower.at(i);
            //si l'endroit cliqué correspond à une case de tower possible prédéfini
            if(CheckCollisionPointRec(mvector,place)){
                for (int j = 0; j < towersPlaced.size(); ++j) {
                    //si une tour existe déjà à cette place
                    if (towersPlaced.at(j).getHitbox().x == place.x && towersPlaced.at(j).getHitbox().y == place.y){
                        notPlacedYet = false;
                    }
                }
                if (notPlacedYet) {
                    float x_pos = (place.x + RATIO);
                    float y_pos = (place.y + RATIO);
                    Rectangle hitboxMissile = Rectangle{x_pos, y_pos, 21, 39};

                    Projectile missile = Projectile("projectile" ,hitboxMissile, 3, {x_pos, y_pos} ,LoadTexture("../resources/missile.png"));

                    //création de la tower
                    Tower tower = inventoryHandler.getCreatorMap().find(
                            inventoryHandler.getSItem().getId())->second(
                                    0.0,
                                    place,
                                    1,
                                    inventoryHandler.getSItem().getId(),
                                    inventoryHandler.getSItem().getImage(),
                                    {place.x + RATIO,place.y + RATIO},
                                    200
                                    );
					//si le joueur à assez d'argent pour acheter la tower               
                    if (tower.getCost() <= player.getMoney()) {
                        towersPlaced.push_back(tower);
                        player.setMoney(player.getMoney() - tower.getCost());
                    }
                }
            }
        }
    }
}
//draw les tower qui sont placées
void TileMapManager::drawTowers(std::vector<Tower> towersPlaced) {
    for (int i = 0; i < towersPlaced.size(); ++i) {
        Tower t = towersPlaced.at(i);
        DrawTexturePro(
                t.getImage(),
                {0,0,64,64},
                {t.getHitbox().x + 32,t.getHitbox().y + 32,64,64},
                {32,32},
                t.getAngle(),
                WHITE);
        DrawCircleLines(t.getCenter().x,t.getCenter().y,t.getRadius(),GREEN);
    }
}
//tir de missile téléguidés lors de détection
void TileMapManager::aim(std::vector<Monster> &monsters,std::vector<Tower> &towersPlaced){

    for (auto & t : towersPlaced) {t.setIsFollowingMonster(false);}
    for (auto & t : towersPlaced) {
        for (auto & m : monsters) {
            //si le monstre rentre dans la zone de détection
            if (CheckCollisionCircleRec(t.getCenter(),t.getRadius(),m.getHitbox()) && !t.isItFollowingMonster()) {
                double angle =
                        (atan2((m.getHitbox().y + RATIO / 1.5) - t.getCenter().y, (m.getHitbox().x + RATIO) - t.getCenter().x) -
                         atan2((t.getHitbox().y + RATIO) - t.getCenter().y, (t.getHitbox().x + RATIO) - t.getCenter().x)) *
                        180 / PI;
                t.setAngle(angle + 90);
                t.setIsFollowingMonster(true);
                Projectile &projectile =  t.getProjectile();
                Rectangle actualMissileHitbox = {projectile.getCenter().x, projectile.getCenter().y, 21,39};
                projectile.setHitbox(actualMissileHitbox);

                //si le missile n'a pas encore touché le monstre, il le suit
                //si le monstre sort du champs, le missile suit celui qui est le plus proche de lui
                if(!CheckCollisionRecs(m.getHitbox(), projectile.getHitbox())) {
                    double deltaX = (m.getHitbox().x + m.getHitbox().width/2) - (projectile.getCenter().x);
                    double deltaY = (m.getHitbox().y) - (projectile.getCenter().y);

                    float MissileAngle = atan2(deltaY, deltaX);

                    projectile.setCenter({projectile.getCenter().x + 3 * cosf(MissileAngle),
                                                        projectile.getCenter().y + 3 * sinf(MissileAngle)});
                    DrawRectangleLines(projectile.getCenter().x,  projectile.getCenter().y, projectile.getHitbox().width, projectile.getHitbox().height, GREEN);




                    DrawTexturePro(
                            projectile.getImage(),
                            {0, 0, 21, 39},
                            {projectile.getCenter().x + 10, projectile.getCenter().y + 19, 21, 39},
                            {10, 19},
                            t.getAngle(),
                            WHITE
                    );
                    //si le missile touche le monstre, il perd de la vie...
                }else{
                    m.setHealth(m.getHealth() - t.getDamageDealt());
                    auto center = Vector2{t.getHitbox().x + RATIO,t.getHitbox().y + RATIO};
                    t.getProjectile().setCenter(center);
                }
                //...et retourne au point de tir initial
            }else if (!isMonsterDetected(monsters,t)){
                auto center = Vector2{t.getHitbox().x + RATIO,t.getHitbox().y + RATIO};
                t.getProjectile().setCenter(center);
            }
        }
    }
}

//check si le monstre rentre dans le cercle de détection de la tower
bool TileMapManager::isMonsterDetected(std::vector<Monster> monsters, Tower t){
    bool res = false;
    for (int i = 0; i < monsters.size(); ++i) {
        Monster m = monsters.at(i);
        res = res || CheckCollisionCircleRec(t.getCenter(),t.getRadius(),m.getHitbox());
    }
    return res;
}

void TileMapManager::drawEndGameScreen(Texture2D tex,int posx) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(tex, posx, 0, WHITE);
        EndDrawing();
    }
}


//handle the damages made to the monsters, their death, and the damage to the player
void TileMapManager::monsterHandling(std::vector<Monster> &createdMonsters, std::vector<Monster> &WaveMonsterList, Trajet monsterTrajet, int &wavesOccuring, int &textFramesCounter, int j, Player &p1 ){
    //damage of monster to the player
    if (createdMonsters[j].isFinish(monsterTrajet)) {
        p1.setHealth(p1.getHealth() - createdMonsters[j].getDamageDealt());
        createdMonsters.erase(createdMonsters.begin() + j);
    }
    //if the monster dies
    if (!createdMonsters[j].isAlive()) {
        p1.setMoney(p1.getMoney() + createdMonsters[j].getMoney());
        createdMonsters.erase(createdMonsters.begin() + j);
    }
    //if all monsters are dead, launch the next wave
    if (createdMonsters.empty()) {
        WaveMonsterList.erase(WaveMonsterList.begin(), WaveMonsterList.end());
        wavesOccuring += 1;
        textFramesCounter = 0;
    }
}

void TileMapManager::endGame(Player p1, int wavesOccuring, std::vector<Waves> allWaves){
    Texture2D gameOver = LoadTexture("../resources/game_over.png");
    Texture2D gg = LoadTexture("../resources/GG.png");
    //End Game screen
    if (p1.getHealth() <= 0 ) { drawEndGameScreen(gameOver,WIDTH / 4); }
    else if(allWaves.size() <= wavesOccuring){
        drawEndGameScreen(gg,0);
    }
}

void TileMapManager::wavesHandling(std::vector<Monster> &createdMonsters, std::vector<Monster> &WaveMonsterList,  std::vector<Waves> allWaves, Trajet monsterTrajet, int &wavesOccuring, int &textFramesCounter, int &i, Player &p1, float &timer, char message[15]){
    char messageToFormat[15] = "WAVE %d" ;
    //display the occuring waves number
    if(WaveMonsterList.empty() && wavesOccuring < 3){
        WaveMonsterList = allWaves[wavesOccuring].getListOfMonsters();
        i=0;
        snprintf(message, 15, messageToFormat , wavesOccuring);
    }
    DrawText(TextSubtext(message, 0, textFramesCounter/14), 580, 550, 33, WHITE);
    //starts to add all monster of the waves into created monsters list, which is the list of alive monsters
    if (timer > 0.5f && i< WaveMonsterList.size()) {
        createdMonsters.push_back(WaveMonsterList[i]);
        i++;
        timer = 0.0f;
    }
    //handle the animation of the monsters
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
        //handle the monster damages, and the end of the wave
        monsterHandling(createdMonsters, WaveMonsterList, monsterTrajet, wavesOccuring, textFramesCounter, j, p1);
    }
}


void TileMapManager::drawAll(Player &p1, Inventory &inventoryHandler, std::vector<Tower> &towersPlaced, Texture2D inventory, Texture2D bg, char msgHealth[10]){
    ClearBackground(RAYWHITE);
    DrawTexture(bg,0,0,WHITE);
    DrawTexture(inventory,1280,0, WHITE);
    inventoryHandler.DrawAllItems();
    inventoryHandler.checkIfneedToChangenDisplay();
    placeTower(towersPlaced, inventoryHandler, p1);
    drawTowers(towersPlaced);
    p1.drawHealth(msgHealth);
    p1.drawMoney();
}

void TileMapManager::launch(){
    InitWindow(WIDTH,HEIGHT,"tower defense");
    Player p1 = Player(25,5) ;
    std::vector<Tower> towersPlaced;
    Inventory inventoryHandler = Inventory();
    SetTargetFPS(60);
    Texture2D bg = LoadTexture("../resources/tower_defense.png");
    Texture2D inventory = LoadTexture("../resources/inventory.png");
    Trajet monsterTrajet = Trajet();

    //création des waves
    std::vector<Waves> allWaves;
    allWaves.emplace_back(Waves( 1, 3,2));
    allWaves.emplace_back(Waves( 2, 6,4));
    allWaves.emplace_back(Waves( 3, 6,14));

    //monsters of the occuring wave
    std::vector<Monster> WaveMonsterList;
    //monster of the wave that are created and alive
    std::vector<Monster> createdMonsters;

    float timer = 0.0f;
    int i = 0;
    int wavesOccuring = 0;
    int textFramesCounter = 0;
    char message[15];
    char msgHealth[10] = "Vie : ";

    while(!WindowShouldClose() && p1.getHealth() > 0 && allWaves.size() > wavesOccuring){
        BeginDrawing();
        drawAll(p1, inventoryHandler, towersPlaced, inventory, bg, msgHealth);
        timer += GetFrameTime();
        textFramesCounter++;

        wavesHandling(createdMonsters, WaveMonsterList, allWaves, monsterTrajet, wavesOccuring, textFramesCounter, i, p1, timer, message);

        //tir les missiles téléguidés
        aim(createdMonsters,towersPlaced);
        EndDrawing();
    }
    endGame(p1, wavesOccuring, allWaves);
}
