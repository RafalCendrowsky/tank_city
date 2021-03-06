#pragma once

#include "tank.h"

class EnemyTank : public Tank {
public:
    EnemyTank(sf::Image image, sf::Vector2<float> position, EntityIterator* iterator);
    bool getStopped();
    void stop() override;
    void run();

private:
    bool stopped;
};