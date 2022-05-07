#pragma once

#include "tank.h"

class PlayerTank: public Tank {
public:
    PlayerTank(sf::Image image, sf::Vector2<float> position, b2World& world, int lives = 3);
    void stop() override;
    int getLives() const;
    void setLives(int lives);
private:
    int lives;
};