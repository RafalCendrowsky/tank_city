#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <box2d/b2_world.h>

template <typename T>
class BaseManager {
public:
    BaseManager(sf::RenderWindow& window, b2World& world);
    void render();
    void update();
    void add(std::shared_ptr<T> entity);
protected:
    std::vector<std::shared_ptr<T>> entities;
    sf::RenderWindow& window;
    b2World& world;
};

template <typename T>
BaseManager<T>::BaseManager(sf::RenderWindow& window, b2World& world): window(window), world(world) {}

template <typename T>
void BaseManager<T>::render() {
    for (std::shared_ptr<T> entity: entities) {
        window.draw(entity->getSprite());
    }
}

template <typename T>
void BaseManager<T>::update() {
    for (int i = 0; i < entities.size(); i++) {
        if (entities.at(i)->isDestroyed()) {
            world.DestroyBody(entities.at(i)->getBody());
            entities.erase(entities.begin() + i);
            i--;
        } else {
            entities.at(i)->update();
        }
    }
}

template<typename T>
void BaseManager<T>::add(std::shared_ptr<T> entity) {
    entities.push_back(entity);
}
