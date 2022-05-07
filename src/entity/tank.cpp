#include "tank.h"
#include <iostream>

Tank::Tank(sf::Image image, sf::Vector2<float> position, EntityIterator* iterator, eDirection direction, double speed, int hp) :
    Entity(image, position, iterator, direction), hp(hp), baseSpeed(speed) {
    className = "tank";
};

int Tank::getHp() const {
    return hp;
};

void Tank::setHp(int newHp) {
    hp = newHp;
};

void Tank::stop() {
    setSpeed(0);
};

std::shared_ptr<Bullet> Tank::shoot() {
    auto position = this->getSprite().getPosition();
    auto size = this->getSprite().getTextureRect().getSize();
    float bulletSpeed = 2 * baseSpeed;
    switch (getDirection()) {
    case RIGHT:
        position.x += size.x * 5 / 4;
        break;
    case LEFT:
        position.x -= size.x * 5 / 4;
        break;
    case UP:
        position.y -= size.y * 3 / 4;
        break;
    case DOWN:
        position.y += size.y * 3 / 4;
        break;
    }
    sf::Image image;
    image.loadFromFile("src/resources/bullet.png");
    std::shared_ptr<Bullet> bulletPointer(new Bullet(image, position, getIterator(), getDirection(), bulletSpeed));
    this->bulletPtr = bulletPointer;
    bulletPtr->rotate(getDirection());
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

void Tank::move(Entity::eDirection direction) {
    setSpeed(baseSpeed);
    Entity::move(direction);
}
