#include <algorithm>
#include <iostream>
#include "application.h"

void Application::update() {
    world.Step(timeStep, velocityIterations, positionIterations);
    playerManager.update();
    bulletManager.update();
    enemyManager.update();
    mapManager.update();
}

void Application::run() {
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

void Application::render() {
    window.clear(sf::Color::Black);
    playerManager.render();
    bulletManager.render();
    enemyManager.render();
    mapManager.render();
}

void Application::onKeyPress(int key) {
    switch (key) {
        case sf::Keyboard::Left:
            currentKey = key;
            playerManager.movePlayer(Entity::eDirection::LEFT);
            break;
        case sf::Keyboard::Right:
            currentKey = key;
            playerManager.movePlayer(Entity::eDirection::RIGHT);
            break;
        case sf::Keyboard::Up:
            currentKey = key;
            playerManager.movePlayer(Entity::eDirection::UP);
            break;
        case sf::Keyboard::Down:
            currentKey = key;
            playerManager.movePlayer(Entity::eDirection::DOWN);
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

void Application::handleEvents() {
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
