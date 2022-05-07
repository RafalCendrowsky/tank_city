#include "player_tank.h"

PlayerTank::PlayerTank(sf::Image image, sf::Vector2<float> position, b2World &world, int lives) : Tank::Tank(image, position, world, UP) {
    className = "playerTank";
};

void PlayerTank::stop() {
    Tank::stop();
}

int PlayerTank::getLives() const {
    return lives;
}

void PlayerTank::setLives(int lives) {
    this->lives = lives;
}
