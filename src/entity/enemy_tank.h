#pragma once

#include "tank.h"
#include "movement_strategy.h"

class EnemyTank: public Tank {
public:
    EnemyTank(sf::Image texture, sf::Vector2<double> position, MovementStrategy strategy);
    void run();
private:
    MovementStrategy strategy;

    friend MovementStrategy;
};