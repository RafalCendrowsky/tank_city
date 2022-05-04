#include <algorithm>
#include "application_manager.h"

void ApplicationManager::update() {
    world.Step(timeStep, velocityIterations, positionIterations);
    playerManager.update();
    bulletManager.update();
    enemyManager.update();
    mapManager.update();
}

void ApplicationManager::run() {
    world.SetContactListener(&contactListener);
    window.setKeyRepeatEnabled(false);
    int count = 0;
    mapManager.createMap();
    while (window.isOpen()) {
        count++;
        if (count > 10000) {
            count = 0;
            enemyManager.act();
        }
        handleEvents();
        update();
        render();
        window.display();
    }
}

void ApplicationManager::render() {
    window.clear(sf::Color::Black);
    playerManager.render();
    bulletManager.render();
    enemyManager.render();
    mapManager.render();
}

void ApplicationManager::onKeyPress(int key) {
    switch (key) {
        case sf::Keyboard::Left:
            currentKey = key;
            playerManager.movePlayer(PlayerTank::eDirection::LEFT);
            break;
        case sf::Keyboard::Right:
            currentKey = key;
            playerManager.movePlayer(PlayerTank::eDirection::RIGHT);
            break;
        case sf::Keyboard::Up:
            currentKey = key;
            playerManager.movePlayer(PlayerTank::eDirection::UP);
            break;
        case sf::Keyboard::Down:
            currentKey = key;
            playerManager.movePlayer(PlayerTank::eDirection::DOWN);
            break;
        case sf::Keyboard::Space:
            playerManager.playerShoot();
            break;
        case sf::Keyboard::Z:
            playerManager.removeBullet();
            break;
        case sf::Keyboard::Escape:
            this->window.close();
        default:
            break;
    }
}

void ApplicationManager::handleEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                onKeyPress(event.key.code);
                break;
            case sf::Event::KeyReleased:
                if (currentKey == event.key.code) {
                    playerManager.stopPlayer();
                }
                break;
            default:
                break;
        }
    }
}
