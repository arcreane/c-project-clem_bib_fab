//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_TOWER_H
#define TOWERDEFENSE_TOWER_H


#include "Projectile.h"
#include "InfoEntities.h"
#include <vector>
#include <string>

class Tower : public InfoEntities{

    std::string id;
    Texture2D image;
    Vector2 center;
    float radius;
    double angle = 0;
    bool isFollowingMonster = false;
    std::vector<Projectile> projectiles;

public:

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::vector<Projectile> &getProjectiles() const;

    void setProjectiles(const std::vector<Projectile> &projectiles);

    Tower(std::string id);

    const Texture2D &getImage() const;

    void setImage(const Texture2D &image);

    Tower(float damageDealt, float timerFrame, Rectangle &hitbox, int speed,const std::string &id,
          const Texture2D &image,Vector2 center,float radius, const std::vector<Projectile> &projectiles);

    const Vector2 &getCenter() const;

    void setCenter(const Vector2 &center);

    float getRadius() const;

    void setRadius(float radius);

    double getAngle();

    void setAngle(double angle);

    bool isItFollowingMonster() const;

    void setIsFollowingMonster(bool isFollowingMonster);
};


#endif //TOWERDEFENSE_TOWER_H
