#pragma once

#include "enemy_tank.h"

class MovementStrategy {
public :
    virtual void executeStrategy(EnemyTank &tank) = 0;
};