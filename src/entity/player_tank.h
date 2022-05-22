#pragma once

#include "tank.h"

class PlayerTank: public Tank {
public:
    PlayerTank(sf::Image image, sf::Vector2<float> position, EntityIterator* iterator, int lives = 2);
    void stop() override;
    int getLives() const;
    void setLives(int newLives);
    void destroy() override;
private:
    int lives = 2;
};