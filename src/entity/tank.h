#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "bullet.h"

class Tank : public Entity
{
public:
    enum eDirection
    {
        RIGHT,
        LEFT,
        UP,
        DOWN
    };
    Tank(sf::Image image, sf::Vector2<float> position, b2World &world, double speed = 0, int hp = 1);
    void move(eDirection direction);
    Bullet &shoot();
    eDirection getDirection() const { return direction; };
    void setDirection(eDirection newDirection) { direction = newDirection; };
    double getSpeed() const { return speed; };
    int getHp() const { return hp; };
    void setSpeed(double newSpeed) { speed = newSpeed; };
    void setHp(int newHp) { hp = newHp; };
    virtual void stop();

private:
    double speed;
    int hp;
    eDirection direction;
};