#pragma once

#include "tank.h"

class PlayerTank: public Tank {
public:
    PlayerTank(sf::Vector2<double> position, b2World& world, int lives);
private:
    int lives;
};