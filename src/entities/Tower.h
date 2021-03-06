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
    Projectile projectile;
    float firerate;
    float timer =100.0f;

private:
    int cost = 2;

public:
    float getFirerate() const;

    void setFirerate(float firerate);

    const std::string &getId() const;

    void setId(const std::string &id);

     Projectile &getProjectile() ;

    void setProjectile( Projectile &projectile);

    Tower(std::string id);

    const Texture2D &getImage() const;

    void setImage(const Texture2D &image);

    Tower(float damageDealt, float timerFrame, Rectangle &hitbox, int speed,const std::string &id,
          const Texture2D &image,Vector2 center,float radius, int cost, Projectile &projectile);

    Tower(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, float firerate, const std::string &id,
                const Texture2D &image,Vector2 center,float radius, int cost ,std::string pathToMissile);

    const Vector2 &getCenter() const;

    void setCenter(const Vector2 &center);

    float getRadius() const;

    void setRadius(float radius);

    double getAngle();

    void setAngle(double angle);

    bool isItFollowingMonster() const;

    void setIsFollowingMonster(bool isFollowingMonster);

    float getCost() const;

    void setCost(float cost);

    float getTimer() const;

    void setTimer(float timer);
};


#endif //TOWERDEFENSE_TOWER_H
