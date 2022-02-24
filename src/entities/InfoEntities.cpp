//
// Created by CYTech Student on 2/23/2022.
//

#include "InfoEntities.h"

float InfoEntities::getX() const {
    return x;
}

void InfoEntities::setX(float x) {
    InfoEntities::x = x;
}

float InfoEntities::getY() const {
    return y;
}

void InfoEntities::setY(float y) {
    InfoEntities::y = y;
}

float InfoEntities::getWith() const {
    return with;
}

void InfoEntities::setWith(float with) {
    InfoEntities::with = with;
}

float InfoEntities::getHeight() const {
    return height;
}

void InfoEntities::setHeight(float height) {
    InfoEntities::height = height;
}

float InfoEntities::getDamageDealt() const {
    return damageDealt;
}

void InfoEntities::setDamageDealt(float damageDealt) {
    InfoEntities::damageDealt = damageDealt;
}

float InfoEntities::getTimerFrame() const {
    return timerFrame;
}

void InfoEntities::setTimerFrame(float timerFrame) {
    InfoEntities::timerFrame = timerFrame;
}

InfoEntities::InfoEntities(float x, float y, float with, float height, float damageDealt, float timerFrame) : x(x),
                                                                                                              y(y),
                                                                                                              with(with),
                                                                                                              height(height),
                                                                                                              damageDealt(
                                                                                                                      damageDealt),
                                                                                                              timerFrame(
                                                                                                                      timerFrame) {}

