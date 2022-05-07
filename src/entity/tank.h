#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "entity.h"
#include "bullet.h"

class Tank : public Entity
{
public:
    Tank(sf::Image image, sf::Vector2<float> position, b2World &world, eDirection direction, double speed = 2, int hp = 1);
    int getHp() const;
    void setHp(int hp);
    bool hasShot();
    virtual void stop();
    std::shared_ptr<Bullet> shoot();
    void removeBullet();

private:
    int hp;
    std::shared_ptr<Bullet> bulletPtr;
    bool shot;
};