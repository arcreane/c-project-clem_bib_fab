//
// Created by CYTech Student on 2/23/2022.
//

#include "TileMapManager.h"
#include <fstream>
using std::ifstream;
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>

TileMapManager::TileMapManager(std::vector<Rectangle> &placesTower, std::vector<Rectangle> &availablePlacesTower) {

}

std::vector<Rectangle> &TileMapManager::getPlacesTower() {
    return TileMapManager::placesTower;
}

void TileMapManager::setPlacesTower(std::vector<Rectangle> &placesTower) {

}

std::vector<Rectangle> &TileMapManager::getAvailablePlacesTower() {
    return TileMapManager::availablePlacesTower;
}

void TileMapManager::setAvailablePlacesTower(std::vector<Rectangle> &availablePlacesTower) {

}

TileMapManager::TileMapManager(const char* file) {
    int id;
    float x=-1,y=-1;
    std::ifstream tileMapsXml;
    std::string line;
    std::string s = "0123456789";
    tileMapsXml.open(file);
    if (tileMapsXml.is_open()){
        while(tileMapsXml){
            std::getline(tileMapsXml,line);
            if(s.find(line[0]) != std::string::npos ){
                y++;
                //si le carractère de fin est une virgule on la supprime
                if (s.find(line[line.size() - 1]) == std::string::npos) {
                    line.pop_back();
                }
                std::stringstream ss( line);
                while(ss.good()){
                    x++;
                    std::string substr;
                    getline( ss, substr, ',' );
                    id = std::stoi(substr);
                    if(std::count(this->idsPlaces.begin(), this->idsPlaces.end(), id)){
                            this->placesTower.push_back({x*WIDTH_TILES,y*HEIGHT_TILES,WIDTH_TILES * 2,HEIGHT_TILES * 2});
                            this->availablePlacesTower.push_back({x*WIDTH_TILES,y*HEIGHT_TILES,WIDTH_TILES * 2,HEIGHT_TILES * 2});
                    }
                }
                x=-1;
            }else{
                y=-1;
            }
        }
    }else{
        std::cout << "Something went wrong while opening " << file;
    }
}
