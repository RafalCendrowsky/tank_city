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
    mapManager.createMap();
    sf::Clock clock;
    sf::Clock enemyTimer;
    float accumulator = 0;
    while (window.isOpen()) {
        if (enemyTimer.getElapsedTime().asSeconds() > 1.8) {
            enemyManager.act();
            enemyTimer.restart();
        }
        accumulator += clock.getElapsedTime().asSeconds();
        clock.restart();
        while (accumulator > timeStep) {
            std::cout << accumulator << std::endl;
            world.Step(timeStep, velocityIterations, positionIterations);
            accumulator -= timeStep;
        }
        handleEvents();
        update();
        render();
        window.display();
        while (clock.getElapsedTime().asSeconds() < timeStep) {}
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
