//
// Created by CYTech Student on 2/24/2022.
//
#include<iostream>
#include "../entities/Monster.h"
#ifndef TOWERDEFENSE_WAVES_H
#define TOWERDEFENSE_WAVES_H


class Waves{
    int nbOfMonsters;
    int id;
    std::vector<Monster> listOfMonsters;
    int numberOfZombies;
    int numberOfSkeletons;


public:
    Waves(int nbOfMonsters, int id, int numberOfZombies, int numberOfSkeletons);


    int getNbOfMonsters() const;

    void setNbOfMonsters(int nbOfMonsters);

    int getId() const;

    void setId(int id);

    const std::vector<Monster> &getListOfMonsters() const;

    void setListOfMonsters(const std::vector<Monster> &listOfMonsters);

    void initListOfMonsters();

    int getNumberOfZombies() const;

    void setNumberOfZombies(int numberOfZombies);

    int getNumberOfSkeletons() const;

    void setNumberOfSkeletons(int numberOfSkeletons);
};
#endif //TOWERDEFENSE_WAVES_H
