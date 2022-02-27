//
// Created by CYTech Student on 2/23/2022.
//

#include "TileMapManager.h"
#include "../entities/Tower.h"
#include "../listener/Inventory.h"
#include <fstream>
using std::ifstream;
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>

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

void TileMapManager::placeTower(std::vector<Tower> &towersPlaced, Inventory &inventoryHandler) {
    bool notPlacedYet = true;
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mvector = GetMousePosition();
        for (int i = 0; i < placesTower.size(); ++i) {
            Rectangle place = placesTower.at(i);
            if(CheckCollisionPointRec(mvector,place)){
                for (int j = 0; j < towersPlaced.size(); ++j) {
                    if (towersPlaced.at(j).getHitbox().x == place.x && towersPlaced.at(j).getHitbox().y == place.y){
                        notPlacedYet = false;
                    }
                }
                if (notPlacedYet) {
                    std::vector<Projectile> v;
                    Tower tower = inventoryHandler.getCreatorMap().find(inventoryHandler.getSItem().getId())->second(1,0.0,place,1,inventoryHandler.getSItem().getId(),inventoryHandler.getSItem().getImage(),v);
                    towersPlaced.push_back(tower);
                }
            }
        }
    }
}

void TileMapManager::drawTowers(std::vector<Tower> towersPlaced) {
    for (int i = 0; i < towersPlaced.size(); ++i) {
        Tower t = towersPlaced.at(i);
        DrawTextureRec(t.getImage(),{0,0,64,64},{t.getHitbox().x,t.getHitbox().y},WHITE);
    }
}
