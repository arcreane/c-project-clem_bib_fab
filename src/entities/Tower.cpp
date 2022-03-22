//
// Created by CYTech Student on 2/23/2022.
//

#include "Tower.h"


const std::string &Tower::getId() const {
    return id;
}

void Tower::setId(const std::string &id) {
    Tower::id = id;
}

Projectile &Tower::getProjectile(){
    return projectile;
}

void Tower::setProjectile(Projectile &projectile) {
    Tower::projectile = projectile;
}

Tower::Tower(std::string id) {
    this->id = id;
}

Tower::Tower(float damageDealt, float timerFrame, Rectangle &hitbox, int speed,const std::string &id,
             const Texture2D &image,Vector2 center,float radius, int cost ,Projectile &projectile) : InfoEntities(damageDealt, timerFrame,
                                                                                                hitbox, speed), id(id),
                                                                                   image(image),
                                                                                   center(center),
                                                                                   radius(radius),
                                                                                   cost(cost),
                                                                                   projectile(projectile) {}

const Texture2D &Tower::getImage() const {
    return image;
}

void Tower::setImage(const Texture2D &image) {
    Tower::image = image;
}

const Vector2 &Tower::getCenter() const {
    return center;
}

void Tower::setCenter(const Vector2 &center) {
    Tower::center = center;
}

float Tower::getRadius() const {
    return radius;
}

void Tower::setRadius(float radius) {
    Tower::radius = radius;
}

double Tower::getAngle() {
    return angle;
}

void Tower::setAngle(double angle) {
    Tower::angle = angle;
}

bool Tower::isItFollowingMonster() const {
    return isFollowingMonster;
}

void Tower::setIsFollowingMonster(bool isFollowingMonster) {
    Tower::isFollowingMonster = isFollowingMonster;
}

float Tower::getCost() const { return cost; }

void Tower::setCost(float cost) { Tower::cost = cost; }
