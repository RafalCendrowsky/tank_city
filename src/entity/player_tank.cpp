#include "player_tank.h"

PlayerTank::PlayerTank(sf::Image image, sf::Vector2<float> position, b2World &world, int lives) : Tank::Tank(image, position, world){};

void PlayerTank::stop()
{
    b2Vec2 velocity(0, 0);
    this->getBody()->SetLinearVelocity(velocity);
};
