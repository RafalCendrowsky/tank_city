#include "bullet.h"

Bullet::Bullet(sf::Image image, sf::Vector2f position, EntityIterator* iterator, eDirection direction, float speed) :
        Entity(image, position, iterator, direction, speed) {
    className = "bullet";
}
