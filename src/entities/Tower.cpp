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

std::vector<Projectile> &Tower::getProjectiles(){
    return projectiles;
}

void Tower::setProjectiles(std::vector<Projectile> &projectiles) {
    Tower::projectiles = projectiles;
}

Tower::Tower(std::string id) {
    this->id = id;
}

Tower::Tower(float damageDealt, float timerFrame, Rectangle &hitbox, int speed,const std::string &id,
             const Texture2D &image,Vector2 center,float radius, std::vector<Projectile> &projectiles) : InfoEntities(damageDealt, timerFrame,
                                                                                                hitbox, speed), id(id),
                                                                                   image(image),
                                                                                   center(center),
                                                                                   radius(radius),
                                                                                   projectiles(projectiles) {}

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
