#pragma once

#include "tank.h"

class EnemyTank: public Tank {
public:
    EnemyTank(sf::Image texture, sf::Vector2<double> position, b2World& world);
    void stop() override;
    virtual void run() = 0;
private:
    bool stopped;
};