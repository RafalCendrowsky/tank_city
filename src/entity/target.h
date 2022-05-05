#pragma once

#include "entity.h"

class Target : public Entity {
public:
    Target(sf::Image image, sf::Vector2f position, b2World& world);
};