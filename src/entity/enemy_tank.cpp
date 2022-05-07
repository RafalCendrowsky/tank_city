#include "enemy_tank.h"

EnemyTank::EnemyTank(sf::Image image, sf::Vector2<float> position, b2World &world) :
    Tank::Tank(image, position, world, DOWN), stopped(false) {};

bool EnemyTank::getStopped() {
    return stopped;
};

void EnemyTank::stop() {
    b2Vec2 velocity(0, 0);
    this->getBody()->SetLinearVelocity(velocity);
    stopped = true;
};


void EnemyTank::run() {
    Tank::eDirection direction = Tank::eDirection(rand() % 4);
    move(direction);
    stopped = false;
}
