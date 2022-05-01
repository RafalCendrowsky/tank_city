#pragma once

#include "entity.h"

class Target : public Entity {
public:
    Target(sf::Vector2f position, b2World& world);
};