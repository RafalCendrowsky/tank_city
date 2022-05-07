#include "tank.h"
#include <iostream>

Tank::Tank(sf::Image image, sf::Vector2<float> position, b2World &world, eDirection direction, double speed, int hp) : Entity(image, position, world), hp(hp) {
    setSpeed(speed);
    setDirection(direction);
};

int Tank::getHp() const {
    return hp;
};

void Tank::setHp(int newHp) {
    hp = newHp;
};

void Tank::stop() {
    b2Vec2 velocity(0, 0);
    this->getBody()->SetLinearVelocity(velocity);
};

std::shared_ptr<Bullet> Tank::shoot() {
    b2Vec2 velocity(0, 0);
    auto position = this->getSprite().getPosition();
    auto size = this->getSprite().getTextureRect().getSize();
    double bulletSpeed = 2 * getSpeed();
    switch (getDirection()) {
    case RIGHT:
        position.x += size.x * 3 / 2;
        velocity.Set(bulletSpeed, 0);
        break;
    case LEFT:
        position.x -= size.x * 3 / 2;
        velocity.Set(-bulletSpeed, 0);
        break;
    case UP:
        position.y -= size.y;
        velocity.Set(0, -bulletSpeed);
        break;
    case DOWN:
        position.y += size.y;
        velocity.Set(0, bulletSpeed);
        break;
    }
    sf::Image image;
    image.loadFromFile("src/resources/bullet.png");
    std::shared_ptr<Bullet> bulletPointer(new Bullet(image, position, *this->getBody()->GetWorld(), velocity));
    this->bulletPtr = bulletPointer;
    return bulletPtr;
};

bool Tank::hasShot() {
    if (this->bulletPtr == nullptr || this->bulletPtr->isDestroyed()) {
        this->bulletPtr = nullptr;
        this->shot = false;
    } else {
        this->shot = true;
    }
    return this->shot;
}

void Tank::removeBullet() {
    this->bulletPtr->destroy();
}
