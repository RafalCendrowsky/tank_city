#include "tank.h"

Tank::Tank(sf::Image image, sf::Vector2<float> position, b2World &world, eDirection direction, double speed, int hp) : Entity(image, position, world), hp(hp), speed(speed), direction(direction){};

void Tank::move(Tank::eDirection direction)
{
    b2Vec2 velocity(0, 0);
    switch (direction)
    {
    case RIGHT:
        velocity.Set(speed, 0);
        break;
    case LEFT:
        velocity.Set(-speed, 0);
        break;
    case UP:
        velocity.Set(0, -speed);
        break;
    case DOWN:
        velocity.Set(0, speed);
        break;
    }
    this->setDirection(direction);
    this->getBody()->SetLinearVelocity(velocity);
};

void Tank::stop()
{
    b2Vec2 velocity(0, 0);
    this->getBody()->SetLinearVelocity(velocity);
};

Bullet &Tank::shoot()
{
    b2Vec2 velocity(0, 0);
    double bulletSpeed = 2 * speed;
    switch (direction)
    {
    case RIGHT:
        velocity.Set(bulletSpeed, 0);
        break;
    case LEFT:
        velocity.Set(-bulletSpeed, 0);
        break;
    case UP:
        velocity.Set(0, -bulletSpeed);
        break;
    case DOWN:
        velocity.Set(0, bulletSpeed);
        break;
    }
    std::unique_ptr<Bullet> bulletPointer;
    bulletPointer.reset(new Bullet((this->getSprite()).getPosition(), this->getBody()->GetWorld(), velocity));
    this->bulletPtr.swap(bulletPointer);
    return *bulletPtr;
};

bool Tank::hasShot()
{
    if (this->bulletPtr == nullptr || this->bulletPtr->isDestroyed())
    {
        this->bulletPtr = nullptr;
        this->shot = false;
    }
    else
    {
        this->shot = true;
    }
    return this->shot;
}