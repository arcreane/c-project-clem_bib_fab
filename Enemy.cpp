//
// Created by CYTech Student on 2/23/2022.
//

#include "Enemy.h"

Enemy::Enemy() {

}

bool Enemy::isActive() const {
    return active;
}

void Enemy::setActive(bool active) {
    Enemy::active = active;
}

const Rectangle &Enemy::getEnemyFrameRec() const {
    return EnemyFrameRec;
}

void Enemy::setEnemyFrameRec(const Rectangle &enemyFrameRec) {
    EnemyFrameRec = enemyFrameRec;
}

const int *Enemy::getEnemyTrajet() const {
    return EnemyTrajet;
}

int Enemy::getEnemyTrajetSens() const {
    return EnemyTrajetSens;
}

void Enemy::setEnemyTrajetSens(int enemyTrajetSens) {
    EnemyTrajetSens = enemyTrajetSens;
}

int Enemy::getEnemyTrajetCount() const {
    return EnemyTrajetCount;
}

void Enemy::setEnemyTrajetCount(int enemyTrajetCount) {
    EnemyTrajetCount = enemyTrajetCount;
}


const Vector2 &Enemy::getEnemyPosition() const {
    return EnemyPosition;
}

void Enemy::setEnemyPosition(const Vector2 &enemyPosition) {
    EnemyPosition = enemyPosition;
}

int Enemy::getEnemyFramesCounter() const {
    return EnemyFramesCounter;
}

void Enemy::setEnemyFramesCounter(int enemyFramesCounter) {
    EnemyFramesCounter = enemyFramesCounter;
}

int Enemy::getEnemyFramesSpeed() const {
    return EnemyFramesSpeed;
}

void Enemy::setEnemyFramesSpeed(int enemyFramesSpeed) {
    EnemyFramesSpeed = enemyFramesSpeed;
}

int Enemy::getEnemyCurrentFrame() const {
    return EnemyCurrentFrame;
}

void Enemy::setEnemyCurrentFrame(int enemyCurrentFrame) {
    EnemyCurrentFrame = enemyCurrentFrame;
}

