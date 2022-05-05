#include "player_manager.h"

PlayerManager::PlayerManager(sf::RenderWindow& window, sf::Vector2<float> spawnPosition, b2World& world) :
    window(window), spawnPosition(spawnPosition), world(world) {
    sf::Image image;
    image.loadFromFile("src/resources/tank.png");
    playerPtr.reset(new PlayerTank(image, spawnPosition, world));
}

void PlayerManager::render() {
    window.draw(playerPtr->getSprite());
    if (bulletPtr != nullptr)
        window.draw(bulletPtr->getSprite());
}

void PlayerManager::update() {
    playerPtr->update();
    if (bulletPtr != nullptr) {
        if (bulletPtr->isDestroyed()) {
            world.DestroyBody(bulletPtr->getBody());
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

//void PlayerManager::removeBullet() {
//    if (bulletPtr != nullptr) {
//        playerPtr->removeBullet();
//    }
//}