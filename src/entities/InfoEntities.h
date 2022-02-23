//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_INFOENTITIES_H
#define TOWERDEFENSE_INFOENTITIES_H


class InfoEntities {
    int x,y,with,height;
    int damageDealt;

public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getWith() const;

    void setWith(int with);

    int getHeight() const;

    void setHeight(int height);

    int getDamageDealt() const;

    void setDamageDealt(int damageDealt);

    InfoEntities(int x, int y, int with, int height, int damageDealt);
};


#endif //TOWERDEFENSE_INFOENTITIES_H
