#include "game_manager.h"
#include <iostream>

void GameManager::movePlayer(PlayerTank::eDirection direction) {
    this->playerPtr->move(direction);
}

PlayerTank& GameManager::startGame(b2World& world) {
    sf::Image image;
    image.loadFromFile("/home/rcen/Coding/PROI/proi_projekt/src/resources/tank.png");
    sf::Vector2<float> pos {0.0f, 0.0f};
    std::unique_ptr<PlayerTank> tempPlayerPtr(new PlayerTank(image, pos, world));
    this->playerPtr.swap(tempPlayerPtr);
    return *this->playerPtr;
}

void GameManager::stopPlayer() {
    this->playerPtr->stop();
}

bool GameManager::playerHasShot() {
    return this->playerPtr->hasShot();
}

Bullet& GameManager::shootPlayer() {
    return this->playerPtr->shoot();
}