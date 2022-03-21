//
// Created by CYTech Student on 2/25/2022.
//

#ifndef TOWERDEFENSE_INVENTORY_H
#define TOWERDEFENSE_INVENTORY_H


#include <map>
#include <string>
#include <functional>
#include "../entities/Tower.h"
#include "Item.h"

class Inventory {
    constexpr static int cost[5] = {2,3,2,2,2};
    float firstx=6,firsty=264,selectx=128,selecty=93,offsetx=14,offsety=14;
    const int numberOfTower = 5;
    const int numberOfTowerOnLine = 4;
    typedef Tower (*createTowerFunction)(float timerFrame, Rectangle &hitbox, int speed,const std::string &id,const Texture2D &image,Vector2 center,float radius, std::vector<Projectile> &projectiles);
    Item sItem ;
    std::vector<Item> items;
    std::map<std::string,createTowerFunction> creatorMap;
    static Tower createT1(float timerFrame, Rectangle &hitbox, int speed,const std::string &id,const Texture2D &image,Vector2 center,float radius, std::vector<Projectile> &projectiles)
                          { return (*new Tower(2,timerFrame,hitbox,1,"Tower1", LoadTexture("../resources/towers/Tower1.png"),center,radius,cost[0],projectiles)); };
    static Tower createT2(float timerFrame, Rectangle &hitbox, int speed, const std::string &id,const Texture2D &image,Vector2 center,float radius, std::vector<Projectile> &projectiles)
                          { return (*new Tower(2,timerFrame,hitbox,1,"Tower2",LoadTexture("../resources/towers/Tower2.png"),center,radius,cost[1],projectiles)); };
    static Tower createT3(float timerFrame, Rectangle &hitbox, int speed, const std::string &id,const Texture2D &image,Vector2 center,float radius, std::vector<Projectile> &projectiles)
                          { return (*new Tower(2,timerFrame,hitbox,1,"Tower3",LoadTexture("../resources/towers/Tower3.png"),center,radius,cost[2],projectiles)); };
    static Tower createT4(float timerFrame, Rectangle &hitbox, int speed, const std::string &id,const Texture2D &image,Vector2 center,float radius, std::vector<Projectile> &projectiles)
                          { return (*new Tower(2,timerFrame,hitbox,1,"Tower4",LoadTexture("../resources/towers/Tower4.png"),center,radius,cost[3],projectiles)); };
    static Tower createT5(float timerFrame, Rectangle &hitbox, int speed, const std::string &id,const Texture2D &image,Vector2 center,float radius, std::vector<Projectile> &projectiles)
                          { return (*new Tower(2,timerFrame,hitbox,1,"Tower5",LoadTexture("../resources/towers/Tower5.png"),center,radius,cost[4],projectiles)); };
public:
    Inventory();

    float getFirstx() const;

    void setFirstx(float firstx);

    float getFirsty() const;

    void setFirsty(float firsty);

    float getSelectx() const;

    void setSelectx(float selectx);

    float getSelecty() const;

    void setSelecty(float selecty);

    const int getNumberOfTower() const;

    const int getNumberOfTowerOnLine() const;

    const Item getSItem() const;

    void setSItem(const Item &sItem);

    const std::vector<Item> &getItems() const;

    void setItems(const std::vector<Item> &items);

    const std::map<std::string, createTowerFunction> &getCreatorMap() const;

    void setCreatorMap(const std::map<std::string, createTowerFunction> &creatorMap);

    void DrawAllItems();

    void checkIfneedToChangeSItem();
};


#endif //TOWERDEFENSE_INVENTORY_H
