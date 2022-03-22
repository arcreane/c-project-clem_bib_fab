//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_PROJECTILE_H
#define TOWERDEFENSE_PROJECTILE_H

#include <string>
#include "InfoEntities.h"


class Projectile {
    std::string id;
    float speed;
    Vector2 center;
    Texture2D image;
    Rectangle hitbox;
public:
    const Vector2 &getCenter() const;

    void setCenter(const Vector2 &center) ;

public:
    Projectile();

    Projectile(const std::string &id, Rectangle &hitbox, float speed, const Vector2 &center, const Texture2D &image);

    const std::string &getId() const;

    void setId(const std::string &id);

    const Texture2D &getImage() const;

    void setImage(const Texture2D &image);

    float getSpeed() const;

    void setSpeed(float speed);

    const Rectangle &getHitbox() const;

    void setHitbox(const Rectangle &hitbox);

};


#endif //TOWERDEFENSE_PROJECTILE_H
