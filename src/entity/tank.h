#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "bullet.h"

class Tank : public Entity
{
public:
    enum e_direction
    {
        RIGHT = 0,
        LEFT = 1,
        TOP = 2,
        BOTTOM = 3
    };
    Tank(sf::Image texture, sf::Vector2<double> position, b2World &world, double speed = 0, int hp = 1);
    void move(e_direction direction);
    Bullet &shoot();
    double getSpeed() { return speed; };
    int getHp() { return hp; };
    void setSpeed(double newSpeed) { speed = newSpeed; };
    void setHp(int newHp) { hp = newHp; };

private:
    double speed;
    int hp;
};