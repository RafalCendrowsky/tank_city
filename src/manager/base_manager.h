#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../entity/entity.h"

template <typename T>
class BaseManager {
public:
    BaseManager(sf::RenderWindow& window, EntityIterator* iterator);
    void render();
    void update();
    void add(std::shared_ptr<T> entity);
    int getKilledEnemies(){return killedEnemies;}
    void setKilledEnemies(int killed){ killedEnemies = killed;}
protected:
    std::vector<std::shared_ptr<T>> entities;
    sf::RenderWindow& window;
    EntityIterator* iterator;
    int points = 0;
    int killedEnemies = 0;
};

template <typename T>
BaseManager<T>::BaseManager(sf::RenderWindow& window, EntityIterator* iterator): window(window), iterator(iterator) {

}

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
            if (entities.at(i)->getClassName() == "enemyTank"){
                points += 200;
                this->setKilledEnemies(getKilledEnemies() +1);
            }
            iterator->remove(entities.at(i).get());
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
