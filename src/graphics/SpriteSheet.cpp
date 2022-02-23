//
// Created by CYTech Student on 2/23/2022.
//

#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(int currentSheet, const char* spriteSheetPath, int wgap, int hgap, int direction) {
    this->currentSheet = currentSheet;
    this->direction = direction;
    this->sSheet = LoadTexture(spriteSheetPath);
    this->wgap = wgap;
    this->hgap = hgap;
}

SpriteSheet::SpriteSheet(SpriteSheet *pSheet) {

}

int SpriteSheet::getCurrentSheet() const {
    return currentSheet;
}

void SpriteSheet::setCurrentSheet(int currentSheet) {
    SpriteSheet::currentSheet = currentSheet;
}

int SpriteSheet::getDirection() const {
    return direction;
}

void SpriteSheet::setDirection(int direction) {
    SpriteSheet::direction = direction;
}

int SpriteSheet::getWgap() const {
    return wgap;
}

void SpriteSheet::setWgap(int wgap) {
    SpriteSheet::wgap = wgap;
}

int SpriteSheet::getHgap() const {
    return hgap;
}

void SpriteSheet::setHgap(int hgap) {
    SpriteSheet::hgap = hgap;
}

const Texture &SpriteSheet::getSSheet() const {
    return sSheet;
}

void SpriteSheet::setSSheet(const Texture &sSheet) {
    SpriteSheet::sSheet = sSheet;
}

&Texture &SpriteSheet::getSSheet() {
    return (Texture &) &this->sSheet;
}


