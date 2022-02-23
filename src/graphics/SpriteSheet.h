//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_SPRITESHEET_H
#define TOWERDEFENSE_SPRITESHEET_H


#include <vector>
#include "raylib.h"

class SpriteSheet {
    int currentSheet = 0;
    int direction = 0;// bas,gauche,droite,haut ---- 0,1,2,3
    int wgap;
    int hgap;
    Texture sSheet;

public:
    SpriteSheet(int currentSheet, const char* spriteSheetPath,int wgap,int hgap, int direction);

    SpriteSheet(SpriteSheet *pSheet);

    int getCurrentSheet() const;

    void setCurrentSheet(int currentSheet);

    int getDirection() const;

    void setDirection(int direction);

    int getWgap() const;

    void setWgap(int wgap);

    int getHgap() const;

    void setHgap(int hgap);

    Texture &getSSheet() ;

    void setSSheet(const Texture &sSheet);
};


#endif //TOWERDEFENSE_SPRITESHEET_H
