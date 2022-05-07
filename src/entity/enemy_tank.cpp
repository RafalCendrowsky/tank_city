#include "enemy_tank.h"

EnemyTank::EnemyTank(sf::Image image, sf::Vector2<float> position, EntityIterator* iterator) :
    Tank::Tank(image, position, iterator, DOWN), stopped(false) {
    className = "enemyTank";
};

bool EnemyTank::getStopped() {
    return stopped;
};

void EnemyTank::stop() {
    setSpeed(0);
    stopped = true;
};


void EnemyTank::run() {
    Tank::eDirection direction = Tank::eDirection(rand() % 4);
    move(direction);
    stopped = false;
}
