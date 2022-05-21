#include "target_manager.h"
#include <iostream>

TargetManager::TargetManager(sf::RenderWindow& window,  sf::Vector2<float> spawnPosition, EntityIterator* iterator) :
    window(window),  spawnPosition(spawnPosition), iterator(iterator) {
    sf::Image image;
    image.loadFromFile("src/resources/target.png");
    targetPtr = std::make_unique<Target>(image, spawnPosition, iterator);
}

void TargetManager::render() {
    window.draw(targetPtr->getSprite());
}

void TargetManager::update() {
    targetPtr->update();
}