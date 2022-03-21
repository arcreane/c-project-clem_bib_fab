//
// Created by CYTech Student on 2/25/2022.
//

#ifndef TOWERDEFENSE_ITEM_H
#define TOWERDEFENSE_ITEM_H


#include <string>
#include "raylib.h"
#include "../graphics/SpriteSheet.h"

class Item {
    Rectangle rec;
    Texture image;
    std::string id;
    int cost;

public:
    Item();

    Item(const Rectangle &rec, const Texture &image, const std::string &id, int cost);

    const Rectangle &getRec() const;

    void setRec(const Rectangle &rec);

    const Texture &getImage() const;

    void setImage(const Texture &image);

    const std::string &getId() const;

    void setId(const std::string &id);

    int getCost() const;

    void setCost(int cost);

};


#endif //TOWERDEFENSE_ITEM_H
