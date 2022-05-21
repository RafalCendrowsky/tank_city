#pragma once
#include <SFML/Graphics.hpp>

class Entity;

class EntityIterator {
public:
    void add(Entity* entity);
    void remove(Entity* entity);
private:
    std::vector<Entity*> entities;

    friend class Entity;
};

class Entity {
public:
    static float SCALE;
    enum eDirection {RIGHT, LEFT, UP, DOWN};
    Entity(const sf::Image& image, sf::Vector2f position, EntityIterator* iterator, eDirection direction = UP, float speed = 0);
    bool isDestroyed() const;
    virtual void destroy();
    float getSpeed() const;
    void setSpeed(float speed);
    eDirection getDirection() const;
    void setDirection(Entity::eDirection direction);
    std::string getClassName() const;
    sf::Sprite getSprite() const;
    EntityIterator *getIterator();
    void update(float timeStep = 1/60.f);
    virtual void move(Entity::eDirection direction);
    void rotate(eDirection direction);
    sf::Vector2f getDelta(float timeStep);
protected:
    std::string className = "entity";
    bool destroyed = false;
private:
    EntityIterator* iterator;
    float speed;
    eDirection direction;
    sf::Sprite sprite;
    sf::Texture texture;

};