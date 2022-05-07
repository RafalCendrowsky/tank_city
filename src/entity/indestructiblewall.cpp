#include "indestructiblewall.h"

IndestructibleWall::IndestructibleWall(sf::Image image, sf::Vector2f position, EntityIterator* iterator) : Entity(image, position, iterator) {
    className = "indestructibleWall";
}

void IndestructibleWall::destroy() {}