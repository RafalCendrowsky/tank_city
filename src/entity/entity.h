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
    virtual void destroy();
    double getSpeed() const;
    void setSpeed(double speed);
    eDirection getDirection() const;
    void setDirection(Entity::eDirection direction);
    std::string getClassName() const;
    sf::Sprite getSprite() const;
    b2Body* getBody();
    void update();
    void move(Entity::eDirection direction);
    void rotate(eDirection direction);
protected:
    std::string className = "entity";
private:
    double speed;
    eDirection direction;
    sf::Sprite sprite;
    sf::Texture texture;
    b2Body* body;
    bool destroyed = false;
};