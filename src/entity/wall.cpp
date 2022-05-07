#include "wall.h"

Wall::Wall(sf::Image image, sf::Vector2f position, EntityIterator* iterator) : Entity(image, position, iterator) {
    className = "wall";
}