#pragma once

#include "tank.h"

class PlayerTank: public Tank {
public:
    PlayerTank(sf::Vector2<float> position, b2World& world, int lives = 3);
    void stop() override;
    int getLives() const { return lives; };
    void setLives(int newLives) { lives = newLives; };
private:
    int lives;
};