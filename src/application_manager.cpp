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

void ApplicationManager::render() {
    this->window.clear(sf::Color::Black);
    for (const Entity& entity : entities) {
        this->window.draw(entity.getSprite());
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
                    // TODO: implement function for stopping the player
                }
                break;
            default:
                break;
        }
    }
}