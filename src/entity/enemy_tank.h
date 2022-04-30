#pragma once

#include "tank.h"
#include "movement_strategy.h"

class EnemyTank: public Tank {
public:
    void run();
private:
    MovementStrategy strategy;
};