#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "entity.h"
#include "bullet.h"

class Tank : public Entity
{
public:
    Tank(sf::Image image, sf::Vector2<float> position, EntityIterator* iterator, eDirection direction, double baseSpeed = 300, int hp = 1);
    int getHp() const;
    void setHp(int hp);
    bool hasShot();
    void move(Entity::eDirection direction) override;
    virtual void stop();
    std::shared_ptr<Bullet> shoot();
    void removeBullet();

private:
    int hp;
    float baseSpeed;
    std::shared_ptr<Bullet> bulletPtr;
    bool shot;
};