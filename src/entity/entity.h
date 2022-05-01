#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/b2_world.h>

class Entity {
public:
    Entity(sf::Image texture, sf::Vector2f position, b2World& world, bool dynamic);
    bool isDestroyed() const;
    void update();
    virtual void destroy();
    sf::Sprite getSprite() const;
    b2Body getBody() const;
private:
    sf::Sprite sprite;
    b2Body* body;
    bool destroyed;
};