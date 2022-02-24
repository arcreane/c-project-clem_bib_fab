//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_INFOENTITIES_H
#define TOWERDEFENSE_INFOENTITIES_H


class InfoEntities {
    float x,y,with,height;
    float damageDealt;
    float timerFrame;

public:
    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getWith() const;

    void setWith(float with);

    float getHeight() const;

    void setHeight(float height);

    float getDamageDealt() const;

    void setDamageDealt(float damageDealt);

    float getTimerFrame() const;

    void setTimerFrame(float timerFrame);

    InfoEntities(float x, float y, float with, float height, float damageDealt, float timerFrame);
};


#endif //TOWERDEFENSE_INFOENTITIES_H
