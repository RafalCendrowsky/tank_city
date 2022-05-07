#pragma once

#include "entity.h"

class Wall : public Entity {
public:
    Wall(sf::Image image, sf::Vector2f position, EntityIterator* iterator);
};