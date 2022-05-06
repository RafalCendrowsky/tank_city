#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>

class Entity {
public:
    static float SCALE;
    enum eDirection {RIGHT, LEFT, UP, DOWN};
    Entity(const sf::Image& image, sf::Vector2f position, b2World& world);
    bool isDestroyed() const;
    bool isBullet() const;
    void update();
    virtual void destroy();
    sf::Sprite getSprite() const;
    b2Body* getBody();
    void rotate(eDirection direction);
protected:
    bool bullet = false;
private:
    sf::Sprite sprite;
    sf::Texture texture;
    b2Body* body;
    bool destroyed = false;
};