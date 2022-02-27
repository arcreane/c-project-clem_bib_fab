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

const std::vector<Projectile> &Tower::getProjectiles() const {
    return projectiles;
}

void Tower::setProjectiles(const std::vector<Projectile> &projectiles) {
    Tower::projectiles = projectiles;
}

Tower::Tower(std::string id) {
    this->id = id;
}

Tower::Tower(float damageDealt, float timerFrame, Rectangle &hitbox, int speed,const std::string &id,
             const Texture2D &image, const std::vector<Projectile> &projectiles) : InfoEntities(damageDealt, timerFrame,
                                                                                                hitbox, speed), id(id),
                                                                                   image(image),
                                                                                   projectiles(projectiles) {}

const Texture2D &Tower::getImage() const {
    return image;
}

void Tower::setImage(const Texture2D &image) {
    Tower::image = image;
}
