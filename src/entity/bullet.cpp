#include "bullet.h"

Bullet::Bullet(sf::Image image, sf::Vector2f position, b2World &world, b2Vec2 velocity) :
        Entity(image, position, world) {
    this->getBody()->SetLinearVelocity(velocity);
    className = "bullet";
}
