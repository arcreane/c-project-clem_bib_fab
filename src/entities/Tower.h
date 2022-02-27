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
    std::vector<Projectile> projectiles;

public:
    Tower(float damageDealt, float timerFrame, Rectangle &hitbox, int speed, const std::string &id,
          const Texture2D &image, const std::vector<Projectile> &projectiles);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::vector<Projectile> &getProjectiles() const;

    void setProjectiles(const std::vector<Projectile> &projectiles);

    Tower(std::string id);

    const Texture2D &getImage() const;

    void setImage(const Texture2D &image);
};


#endif //TOWERDEFENSE_TOWER_H
