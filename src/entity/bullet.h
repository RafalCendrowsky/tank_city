#pragma once

#include "entity.h"

class Bullet : public Entity {
public:
    Bullet(sf::Vector2f position, b2World& world);
private:
};