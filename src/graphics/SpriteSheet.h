//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_SPRITESHEET_H
#define TOWERDEFENSE_SPRITESHEET_H


#include <vector>
#include "raylib.h"

class SpriteSheet {
    float currentSheet = 0;
    float direction = 0;// bas,gauche,droite,haut ---- 0,1,2,3
    float wgap;
    float hgap;
    Texture sSheet;

public:
    SpriteSheet(float currentSheet, float direction, float wgap, float hgap, const Texture &sSheet);

    float getCurrentSheet() const;

    void setCurrentSheet(float currentSheet);

    float getDirection() const;

    void setDirection(float direction);

    float getWgap() const;

    void setWgap(float wgap);

    float getHgap() const;

    void setHgap(float hgap);

    const Texture &getSSheet() const;

    void setSSheet(const Texture &sSheet);


};


#endif //TOWERDEFENSE_SPRITESHEET_H
