//
// Created by CYTech Student on 2/23/2022.
//

#include "InfoEntities.h"

int InfoEntities::getX() const {
    return x;
}

void InfoEntities::setX(int x) {
    InfoEntities::x = x;
}

int InfoEntities::getY() const {
    return y;
}

void InfoEntities::setY(int y) {
    InfoEntities::y = y;
}

int InfoEntities::getWith() const {
    return with;
}

void InfoEntities::setWith(int with) {
    InfoEntities::with = with;
}

int InfoEntities::getHeight() const {
    return height;
}

void InfoEntities::setHeight(int height) {
    InfoEntities::height = height;
}

int InfoEntities::getDamageDealt() const {
    return damageDealt;
}

void InfoEntities::setDamageDealt(int damageDealt) {
    InfoEntities::damageDealt = damageDealt;
}

InfoEntities::InfoEntities(int x, int y, int with, int height, int damageDealt) : x(x), y(y), with(with),
                                                                                  height(height),
                                                                                  damageDealt(damageDealt) {}
