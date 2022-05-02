#include <algorithm>
#include "application_manager.h"

void ApplicationManager::update() {
    for (int i = 0; i < this->entities.size(); i++) {
        if (this->entities.at(i).isDestroyed()) {
            this->entities.erase(this->entities.begin() + i);
            i--;
        } else {
            this->entities.at(i).update();
        }
    }
}

void ApplicationManager::run() {
    while (window.isOpen()) {
        this->handleEvents();
        this->update();
        this->render();
        this->window.display();
    }
}

void ApplicationManager::render() {
    this->window.clear(sf::Color::Black);
    for (const Entity& entity : entities) {
        this->window.draw(entity.getSprite());
    }
}

void ApplicationManager::onKeyPress(int key) {
    switch (key) {
        case sf::Keyboard::Left:
            this->gameManager.movePlayer(PlayerTank::eDirection::LEFT);
            break;
        case sf::Keyboard::Right:
            this->gameManager.movePlayer(PlayerTank::eDirection::RIGHT);
            break;
        case sf::Keyboard::Up:
            this->gameManager.movePlayer(PlayerTank::eDirection::UP);
            break;
        case sf::Keyboard::Down:
            this->gameManager.movePlayer(PlayerTank::eDirection::DOWN);
            break;
        default:
            break;
    }
}

void ApplicationManager::handleEvents() {
    sf::Event event{};
    std::vector<sf::Keyboard::Key> movementKeys {sf::Keyboard::Left, sf::Keyboard::Right,
                                                 sf::Keyboard::Up, sf::Keyboard::Down};
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                this->onKeyPress(event.key.code);
                break;
            case sf::Event::KeyReleased:
                if (*std::find(movementKeys.begin(), movementKeys.end(),
                               event.key.code)== event.key.code) {
                    this->gameManager.stopPlayer();
                }
                break;
            default:
                break;
        }
    }
}
