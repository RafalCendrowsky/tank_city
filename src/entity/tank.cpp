#include "tank.h"
#include "entity.h"
#include "bullet.h"

Tank::Tank(sf::Image image, sf::Vector2<float> position, b2World &world, double speed, int hp) : Entity(image, position, world), hp(hp), speed(speed){};

void Tank::move(Tank::eDirection direction){
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
    this->getBody()->SetLinearVelocity(velocity);
};

void Tank::stop(){
    b2Vec2 velocity(0,0);
    this->getBody()->SetLinearVelocity(velocity);
};

Bullet &Tank::shoot()
{
    std::unique_ptr<Bullet> bulletPtr;
    b2Vec2 velocity(); // dodać wektor - add vector (translated for Rafał)
    bulletPtr.reset(new Bullet((this->getSprite()).getPosition(), this->getBody()->GetWorld(), velocity));
    return *bulletPtr;
};
