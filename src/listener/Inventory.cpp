//
// Created by CYTech Student on 2/25/2022.
//

#include <iostream>
#include <utility>
#include "Inventory.h"
#include "../tile/TileMapManager.h"

typedef Tower (*createTowerFunction)(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, const std::string &id,
                                     const Texture2D &image, const std::vector<Projectile> &projectiles);

Inventory::Inventory() {
    int x=1,y=0;
    int ct = 0,i=-1;
    std::string path;
    while((int) ct != numberOfTower) {
            i++;
            path = "../resources/towers/Tower" + std::to_string((x)) + ".png";
            Texture texture =  LoadTexture(path.c_str());
            std::cout << (float) i<< std::endl;
            items.push_back((*new Item({WIDTH_GAME + firstx + (i * offsetx) + (i*64) , firsty + (y*offsety) + (y*64),64,64}, texture,"Tower" + std::to_string((x)))));
            ct++;
            x++;
        if (i == numberOfTowerOnLine - 1){
            i = -1;
            y++;
        }
    }
    Inventory::sItem = (*new Item({WIDTH_GAME + 128,93,64,64},LoadTexture("../resources/towers/Tower1.png"),"Tower1"));
    Inventory::creatorMap.emplace("Tower1",&(Inventory::createT1));
    Inventory::creatorMap.emplace("Tower2",&(Inventory::createT2));
    Inventory::creatorMap.emplace("Tower3",&(Inventory::createT3));
    Inventory::creatorMap.emplace("Tower4",&(Inventory::createT4));
    Inventory::creatorMap.emplace("Tower5",&(Inventory::createT5));
}

float Inventory::getFirstx() const {
    return firstx;
}

void Inventory::setFirstx(float firstx) {
    Inventory::firstx = firstx;
}

float Inventory::getFirsty() const {
    return firsty;
}

void Inventory::setFirsty(float firsty) {
    Inventory::firsty = firsty;
}

float Inventory::getSelectx() const {
    return selectx;
}

void Inventory::setSelectx(float selectx) {
    Inventory::selectx = selectx;
}

float Inventory::getSelecty() const {
    return selecty;
}

void Inventory::setSelecty(float selecty) {
    Inventory::selecty = selecty;
}

const int Inventory::getNumberOfTower() const {
    return numberOfTower;
}

const int Inventory::getNumberOfTowerOnLine() const {
    return numberOfTowerOnLine;
}

const Item Inventory::getSItem() const {
    return sItem;
}

void Inventory::setSItem(const Item &sItem) {
    Inventory::sItem.setId(sItem.getId());
    Inventory::sItem.setImage(sItem.getImage());
}

const std::vector<Item> &Inventory::getItems() const {
    return items;
}

void Inventory::setItems(const std::vector<Item> &items) {
    Inventory::items = items;
}


void Inventory::DrawAllItems() {
    for (int i = 0; i < Inventory::items.size(); ++i) {
        DrawTextureRec(
                Inventory::items.at(i).getImage(),
                {0,0,64,64},
                {Inventory::items.at(i).getRec().x,Inventory::items.at(i).getRec().y},
                WHITE
        );
    }
    DrawTextureRec(
            Inventory::sItem.getImage(),
            {0,0,64,64},
            {Inventory::sItem.getRec().x,Inventory::sItem.getRec().y},
            WHITE
    );
}

void Inventory::checkIfneedToChangeSItem(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector2 mvector = GetMousePosition();
        for (int i = 0; i < items.size(); ++i) {
            Item it = items.at(i);
            if (CheckCollisionPointRec(mvector,it.getRec())){
                Inventory::setSItem(it);
            }
        }
    }
}

const std::map<std::string, createTowerFunction> &Inventory::getCreatorMap() const {
    return creatorMap;
}

void Inventory::setCreatorMap(const std::map<std::string, createTowerFunction> &creatorMap) {
    Inventory::creatorMap = creatorMap;
}
