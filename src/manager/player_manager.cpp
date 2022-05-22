#include "player_manager.h"
#include <iostream>

PlayerManager::PlayerManager(sf::RenderWindow& window, sf::Vector2<float> spawnPosition, EntityIterator* iterator) :
    window(window), spawnPosition(spawnPosition), iterator(iterator) {
    sf::Image image;
    image.loadFromFile("src/resources/tank.png");
    playerPtr = std::make_unique<PlayerTank>(image, spawnPosition, iterator);
}

void PlayerManager::render() {
    window.draw(playerPtr->getSprite());
    if (bulletPtr != nullptr)
        window.draw(bulletPtr->getSprite());
}

void PlayerManager::update() {
    playerPtr->update();
        if (playerPtr->isDestroyed()) {
        window.close();
    }
    if (bulletPtr != nullptr) {
        if (bulletPtr->isDestroyed()) {
            iterator->remove(bulletPtr.get());
            bulletPtr = nullptr;
        } else {
            bulletPtr->update();
        }
    }
}

void PlayerManager::stopPlayer() {
    playerPtr->stop();
}

void PlayerManager::movePlayer(Entity::eDirection direction) {
    playerPtr->move(direction);
}

void PlayerManager::playerShoot() {
    if (!playerPtr->hasShot()) {
        bulletPtr = playerPtr->shoot();
    }
}

void PlayerManager::removeBullet() {
    if (bulletPtr != nullptr) {
        playerPtr->removeBullet();
    }
}