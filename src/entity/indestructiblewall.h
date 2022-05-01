#pragma once

#include "entity.h"

class IndestructibleWall : public Entity {
public:
    Wall(sf::Vector2f position, b2World& world);
};