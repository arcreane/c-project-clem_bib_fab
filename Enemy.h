//
// Created by CYTech Student on 2/23/2022.
//

#ifndef TOWERDEFENSE_ENEMY_H
#define TOWERDEFENSE_ENEMY_H


#include "raylib.h"

class Enemy {
private:
    bool active;
    Rectangle EnemyFrameRec;
    int EnemyTrajet[7] {110,35,270,200,490,125};
    int EnemyTrajetSens;
    int EnemyTrajetCount;
    Vector2 EnemyPosition;
    int EnemyFramesCounter;
    int EnemyFramesSpeed;
    int EnemyCurrentFrame;
public:
    Enemy();

    bool isActive() const;

    void setActive(bool active);

    const Rectangle &getEnemyFrameRec() const;

    void setEnemyFrameRec(const Rectangle &enemyFrameRec);

    const int *getEnemyTrajet() const;

    int getEnemyTrajetSens() const;

    void setEnemyTrajetSens(int enemyTrajetSens);

    int getEnemyTrajetCount() const;

    void setEnemyTrajetCount(int enemyTrajetCount);


    const Vector2 &getEnemyPosition() const;

    void setEnemyPosition(const Vector2 &enemyPosition);

    int getEnemyFramesCounter() const;

    void setEnemyFramesCounter(int enemyFramesCounter);

    int getEnemyFramesSpeed() const;

    void setEnemyFramesSpeed(int enemyFramesSpeed);

    int getEnemyCurrentFrame() const;

    void setEnemyCurrentFrame(int enemyCurrentFrame);
};


#endif //TOWERDEFENSE_ENEMY_H
