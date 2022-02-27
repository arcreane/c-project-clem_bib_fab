//
// Created by CYTech Student on 2/23/2022.
//

#include <iostream>
#include "SpriteSheet.h"


SpriteSheet::SpriteSheet(float currentSheet, float direction, float wgap, float hgap, const Texture &sSheet)
        : currentSheet(currentSheet), direction(direction), wgap(wgap), hgap(hgap), sSheet(sSheet) {}

float SpriteSheet::getCurrentSheet() const {
    return currentSheet;
}

void SpriteSheet::setCurrentSheet(float currentSheet) {
    SpriteSheet::currentSheet = currentSheet;
}

float SpriteSheet::getDirection() const {
    return direction;
}

void SpriteSheet::setDirection(float direction) {
    SpriteSheet::direction = direction;
}

float SpriteSheet::getWgap() const {
    return wgap;
}

void SpriteSheet::setWgap(float wgap) {
    SpriteSheet::wgap = wgap;
}

float SpriteSheet::getHgap() const {
    return hgap;
}

void SpriteSheet::setHgap(float hgap) {
    SpriteSheet::hgap = hgap;
}

const Texture &SpriteSheet::getSSheet() const {
    return sSheet;
}

void SpriteSheet::setSSheet(const Texture &sSheet) {
    SpriteSheet::sSheet = sSheet;
}

SpriteSheet::SpriteSheet() {}
