#include "player_tank.h"

PlayerTank::PlayerTank(sf::Image image, sf::Vector2<float> position, b2World &world, int lives) : Tank::Tank(image, position, world, UP){};

void PlayerTank::stop()
{
    Tank::stop();
}
