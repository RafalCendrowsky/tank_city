#include "wall.h"

Wall::Wall(sf::Image image, sf::Vector2f position, b2World& world) : Entity(image, position, world) {}