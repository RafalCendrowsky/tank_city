#include "enemy_tank.h"

EnemyTank::EnemyTank(sf::Image image, sf::Vector2<float> position, b2World &world) : Tank::Tank(image, position, world), stopped(false){};

void EnemyTank::stop()
{
    b2Vec2 velocity(0, 0);
    this->getBody()->SetLinearVelocity(velocity);
    setIsStopped(true);
};


void EnemyTank::run()
{   Tank::eDirection direction = Tank::eDirection(rand() % 4);
    move(direction);
    setIsStopped(false);
};
