#pragma once

#include "tank.h"

class PlayerTank: public Tank {
public:
    PlayerTank(sf::Vector2<double> position, int lives);
private:
    int lives;
};