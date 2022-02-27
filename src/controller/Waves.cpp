//
// Created by CYTech Student on 2/24/2022.
//

#include "Waves.h"
#include "../entities/Trajet.h"
#include <vector>

constexpr  float WIDTH = 1280, HEIGHT = 800;
constexpr  float WIDTH_Z = 32, HEIGHT_Z = 44;

Waves::Waves(int nbOfMonsters, int id, int numberOfZombies, int numberOfSkeletons) : nbOfMonsters(nbOfMonsters), id(id),
                                                                                     numberOfZombies(numberOfZombies),
                                                                                     numberOfSkeletons(
                                                                                             numberOfSkeletons) {
    initListOfMonsters();
}

int Waves::getNbOfMonsters() const {
    return nbOfMonsters;
}

void Waves::setNbOfMonsters(int nbOfMonsters) {
    Waves::nbOfMonsters = nbOfMonsters;
}

int Waves::getId() const {
    return id;
}

void Waves::setId(int id) {
    Waves::id = id;
}

const std::vector<Monster> &Waves::getListOfMonsters() const {
    return listOfMonsters;
}

void Waves::setListOfMonsters(const std::vector<Monster> &listOfMonsters) {
    Waves::listOfMonsters = listOfMonsters;
}

int Waves::getNumberOfZombies() const {
    return numberOfZombies;
}

void Waves::setNumberOfZombies(int numberOfZombies) {
    Waves::numberOfZombies = numberOfZombies;
}

int Waves::getNumberOfSkeletons() const {
    return numberOfSkeletons;
}

void Waves::setNumberOfSkeletons(int numberOfSkeletons) {
    Waves::numberOfSkeletons = numberOfSkeletons;
}

void Waves::initListOfMonsters(){
    std::vector<Monster> initList;
    Trajet monsterTrajet = Trajet();
    //set Monstertype to 0 for zombie, and 96 for skeleton with the zombie_n_skeleton2.png
    Rectangle recZombies = {(float) monsterTrajet.getEnemyTrajet().at(0).x - (WIDTH_Z / 2),
                            (float) monsterTrajet.getEnemyTrajet().at(0).y - HEIGHT_Z,
                            WIDTH_Z,
                            HEIGHT_Z};
    Rectangle recSkeleton = {(float)monsterTrajet.getEnemyTrajet().at(0).x - (WIDTH_Z/2),(float)monsterTrajet.getEnemyTrajet().at(0).y - HEIGHT_Z,WIDTH_Z,HEIGHT_Z};
    Monster zombie = Monster(5,
                             0.0,
                             recZombies,1,5,
                              *(new SpriteSheet(0,3, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png")))
                              ,0);
    Monster skeleton = Monster(5,0.0,
                               recSkeleton,1,5,*(new SpriteSheet(0,3, 32, 64,LoadTexture("../resources/zombie_n_skeleton2.png"))),96);

    for (int i = 0; i < Waves::numberOfZombies; ++i) {
        initList.push_back(zombie);
    }
    for (int i = 0; i < Waves::numberOfSkeletons; ++i) {
        initList.push_back(skeleton);
    }
    Waves::setListOfMonsters(initList);
}

//Créer des fonctions permettant d'initialiser la liste et de retirer des monstres de la liste