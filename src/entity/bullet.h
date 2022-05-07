#pragma once

#include "entity.h"

class Bullet : public Entity {
public:
    Bullet(sf::Image image, sf::Vector2f position, EntityIterator* iterator, eDirection direction, float speed);
};