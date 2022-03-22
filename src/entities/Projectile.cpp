//
// Created by CYTech Student on 2/23/2022.
//

#include "Projectile.h"


Projectile::Projectile() {}


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

const Vector2 &Projectile::getCenter() const {
    return center;
}

void Projectile::setCenter(const Vector2 &center)  {
    Projectile::center = center;
}

Projectile::Projectile(const std::string &id,  Rectangle &hitbox,float speed, const Vector2 &center, const Texture2D &image) : id(id),
                                                                                                            speed(speed),
                                                                                                            center(center),
                                                                                                            image(image),
                                                                                                            hitbox(hitbox){}

float Projectile::getSpeed() const { return speed; }

void Projectile::setSpeed(float speed) { Projectile::speed = speed; }

const Rectangle &Projectile::getHitbox() const { return hitbox; }

void Projectile::setHitbox(const Rectangle &hitbox) { Projectile::hitbox = hitbox; }

