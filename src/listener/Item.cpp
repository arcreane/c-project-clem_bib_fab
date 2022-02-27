//
// Created by CYTech Student on 2/25/2022.
//

#include "Item.h"

#include <utility>

Item::Item() {}

Item::Item(const Rectangle &rec,  const Texture &image,  const std::string &id) : rec(rec), image(image), id(id) {}

const Rectangle &Item::getRec() const {
    return rec;
}

void Item::setRec(const Rectangle &rec) {
    Item::rec = rec;
}

const Texture &Item::getImage() const {
    return image;
}

void Item::setImage(const Texture &image) {
    Item::image = image;
}

const std::string &Item::getId() const {
    return id;
}

void Item::setId(const std::string &id) {
    Item::id = id;
}

