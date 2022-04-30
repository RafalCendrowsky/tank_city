#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "bullet.h"

class Tank: public Entity {
public:
    enum e_direction {RIGHT = 0, LEFT = 1, TOP = 2, BOTTOM = 3};
    Tank(sf::Image texture, sf::Vector2<double> position, double speed, int hp = 1);;
    void move(e_direction direction);
    Bullet& shoot();
    void stop();
private:
    double speed;
    int hp;
};