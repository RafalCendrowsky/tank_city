#pragma once

#include "entity.h"

class IndestructibleWall : public Entity {
public:
    IndestructibleWall(sf::Vector2f position, b2World& world);
    virtual void destroy() override;
};