#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/b2_world.h>

class Entity {
public:
    Entity(sf::Image texture, sf::Vector2f position, b2World& world, bool dynamic);
    bool isDestroyed();
    void update();
    void destroy();
private:
    sf::Sprite sprite;
    sf::Vector2f position;
    b2Body* body;
    bool destroyed;
};