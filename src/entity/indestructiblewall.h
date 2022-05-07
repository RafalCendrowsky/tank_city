#pragma once

#include "entity.h"

class IndestructibleWall : public Entity {
public:
    IndestructibleWall(sf::Image image, sf::Vector2f position, EntityIterator* iterator);
    void destroy() override;
};