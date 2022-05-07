#pragma once
#include <SFML/Graphics.hpp>

class Entity;

class EntityIterator {
public:
    void add(Entity* entity);
    void remove(Entity* entity);
private:
    std::vector<Entity*> entities;
};

class Entity {
public:
    static float SCALE;
    enum eDirection {RIGHT, LEFT, UP, DOWN};
    Entity(const sf::Image& image, sf::Vector2f position);
    bool isDestroyed() const;
    virtual void destroy();
    double getSpeed() const;
    void setSpeed(double speed);
    eDirection getDirection() const;
    void setDirection(Entity::eDirection direction);
    std::string getClassName() const;
    sf::Sprite getSprite() const;
    void update();
    void move(Entity::eDirection direction);
    void rotate(eDirection direction);
protected:
    std::string className = "entity";
private:
    EntityIterator iterator;
    float speed;
    eDirection direction;
    sf::Sprite sprite;
    sf::Texture texture;
    bool destroyed = false;
};