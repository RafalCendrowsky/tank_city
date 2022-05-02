#include "tank.h"
#include "entity.h"
#include "bullet.h"
#include <box2d/b2_math.h>

Tank::Tank(sf::Image texture, sf::Vector2<float> position, b2World &world, double speed, int hp) : Entity(texture, position, world, true), hp(hp), speed(speed){};

void Tank::move(Tank::e_direction direction){
    b2Vec2 velocity(0,0);
    speed = this->getSpeed();
    switch ( direction )
    {
    case 0:
    velocity.Set(speed, 0);
    break;
    case 1:
    velocity.Set(-speed, 0);
    break;
    case 2:
    velocity.Set(0, speed);
    break;
    case 3:
    velocity.Set(0, -speed);
    break;
    }
    this->getBody()->setLinearVelocity(&velocity);
};

Bullet &Tank::shoot()
{
    std::unique_ptr<Bullet> bulletPtr;
    b2Vec2 velocity(); // dodać wektor - add vector (translated for Rafał)
    bulletPtr.reset(new Bullet((this->getSprite()).getPosition(), this->getBody()->getWorld(), velocity));
    return *bulletPtr;
};
