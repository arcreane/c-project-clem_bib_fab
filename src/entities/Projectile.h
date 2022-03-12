//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_PROJECTILE_H
#define TOWERDEFENSE_PROJECTILE_H

#include <string>
#include "InfoEntities.h"


class Projectile : public InfoEntities{
    std::string id;
    float speed;
    Vector2 center;
public:
    const Vector2 &getCenter() const;

    void setCenter(const Vector2 &center) ;

private:
    Texture2D image;
    float radius;
    double angle = 0;
public:
    Projectile();

    Projectile(float damageDealt , float timerFrame, Rectangle &hitbox, int speed, Vector2 center, const std::string &id,
               const Texture2D &image,float radius);

    const std::string &getId() const;

    void setId(const std::string &id);

    const Texture2D &getImage() const;

    void setImage(const Texture2D &image);

    float getRadius() const;

    void setRadius(float radius);

    double getAngle() const;

    void setAngle(double angle);

};


#endif //TOWERDEFENSE_PROJECTILE_H
