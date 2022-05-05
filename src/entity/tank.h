#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "entity.h"
#include "bullet.h"

class Tank : public Entity
{
public:
    Tank(sf::Image image, sf::Vector2<float> position, b2World &world, eDirection direction, double speed = 2, int hp = 1);
    void move(Entity::eDirection direction);
    std::shared_ptr<Bullet> shoot();
    eDirection getDirection() const { return direction; };
    void setDirection(Entity::eDirection newDirection) { direction = newDirection; };
    int getHp() const { return hp; };
    void setSpeed(double newSpeed) { speed = newSpeed; };
    void setHp(int newHp) { hp = newHp; };
    virtual void stop();
    bool hasShot();
    void removeBullet();

private:
    double speed;
    int hp;
    eDirection direction;
    std::shared_ptr<Bullet> bulletPtr;
    bool shot;
};