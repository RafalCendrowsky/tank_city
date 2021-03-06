#include "player_tank.h"

PlayerTank::PlayerTank(sf::Image image, sf::Vector2<float> position, EntityIterator *iterator, int lives) : Tank::Tank(image, position, iterator, UP) {
    className = "playerTank";
    spawnPosition = position;
};

void PlayerTank::stop() {
    Tank::stop();
}

int PlayerTank::getLives() const {
    return lives;
}

void PlayerTank::setLives(int newLives) {
    lives = newLives;
}

void PlayerTank::destroy(){
    if (this->getLives() > 1){
        this->setLives(this->getLives() - 1);
        resetPosition();
    }
    else{
        destroyed = true;
    }
}

void PlayerTank::resetPosition() {
    stop();
    setPosition(spawnPosition);
    rotate(UP);
}
