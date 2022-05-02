#include "tank.h"
#include <memory>
#include "entity.h"
#include "bullet.h"

Tank::Tank(sf::Image image, sf::Vector2<double> position, b2World& world, double speed = 0, int hp = 1):
    Entity(image, position, world), hp(hp), speed(speed) {};

void Tank::move(Tank::e_direction direction){

};

Bullet& Tank::shoot(){
    std::unique_ptr<Bullet> bulletPtr;
    b2Vec2 velocity(); //dodać wektor
    bulletPtr.reset(new Bullet((this->getSprite()).getPosition(), this->getBody().getWorld(), velocity));
    return *bulletPtr;
};
