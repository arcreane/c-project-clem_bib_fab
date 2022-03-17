//
// Created by CYTech Student on 2/23/2022.
//

#include "Projectile.h"


Projectile::Projectile() {

}

Projectile::Projectile(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, Vector2 center, const std::string &id,
             const Texture2D &image,float radius) : InfoEntities(damageDealt, timerFrame,hitbox, speed), center(center), id(id),
                                                                                                               image(image),
                                                                                                               radius(radius) {}

const std::string &Projectile::getId() const {
    return id;
}

void Projectile::setId(const std::string &id) {
    Projectile::id = id;
}


const Texture2D &Projectile::getImage() const {
    return image;
}

void Projectile::setImage(const Texture2D &image) {
    Projectile::image = image;
}

float Projectile::getRadius() const {
    return radius;
}

void Projectile::setRadius(float radius) {
    Projectile::radius = radius;
}

double Projectile::getAngle() const {
    return angle;
}

void Projectile::setAngle(double angle) {
    Projectile::angle = angle;
}

const Vector2 &Projectile::getCenter() const {
    return center;
}

void Projectile::setCenter(const Vector2 &center)  {
    Projectile::center = center;
}
