#pragma once

#include "tank.h"

class EnemyTank : public Tank
{
public:
    EnemyTank(sf::Image image, sf::Vector2<float> position, b2World &world);
    void stop() override;
    void run();
    bool getStopped() { return stopped; };

private:
    bool stopped;
};