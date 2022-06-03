#include "entity.h"
#include <iostream>

void EntityIterator::remove(Entity *entity) {
    int i = 0;
    for (auto entityI: entities) {
        if (entityI == entity) {
            entities.erase(entities.begin() + i);
        }
        i++;
    }
}



Entity::Entity(const sf::Image& image, sf::Vector2f position, EntityIterator* iterator, eDirection direction, float speed) :
    direction(direction), speed(speed), iterator(iterator) {
    if (!texture.loadFromImage(image))
        throw std::invalid_argument("Invalid image for texture");
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2<float> {texture.getSize().x / 2.f, texture.getSize().y / 2.f});
    iterator->entities.push_back(this);
}

bool Entity::isDestroyed() const {
    return destroyed;
}

void Entity::destroy() {
    destroyed = true;
}

float Entity::getSpeed() const {
    return speed;
};

void Entity::setSpeed(float speed) {
    this->speed = speed;
}

Entity::eDirection Entity::getDirection() const {
    return direction;
}

void Entity::setDirection(Entity::eDirection direction) {
    this->direction = direction;
};

std::string Entity::getClassName() const {
    return className;
};

void Entity::move(Entity::eDirection direction) {
    rotate(direction);
};

sf::Sprite Entity::getSprite() const {
    return sprite;
}

void Entity::update(float timeStep) {
    auto position = sprite.getPosition();
    sprite.setPosition(position + getDelta(timeStep));
    for (auto entity: iterator->entities) {
        if (entity == this) continue;
        if (sprite.getGlobalBounds().findIntersection(
                entity->getSprite().getGlobalBounds()) != std::nullopt) {
            if (className == "bullet" && !isDestroyed()) {
                destroy();
                entity->destroy();
            }
            sprite.setPosition(position);
            break;
        }
    }
}

void Entity::rotate(Entity::eDirection direction) {
    setDirection(direction);
    switch (direction) {
        case RIGHT:
            sprite.setRotation(sf::degrees(90.f));
            break;
        case LEFT:
            sprite.setRotation(sf::degrees(-90.f));
            break;
        case UP:
            sprite.setRotation(sf::degrees(0.f));
            break;
        case DOWN:
            sprite.setRotation(sf::degrees(180.f));
            break;
        default:
            break;
    }
}

sf::Vector2f Entity::getDelta(float timeStep) {
    switch (direction) {
        case RIGHT:
            return sf::Vector2f {speed * timeStep, 0};
        case LEFT:
            return sf::Vector2f {-speed * timeStep, 0};
        case UP:
            return sf::Vector2f {0, -speed * timeStep};
        default:
            return sf::Vector2f {0, speed * timeStep};
    }
}

EntityIterator *Entity::getIterator() {
    return iterator;
}

void Entity::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void Entity::resetDestroyed() {
    destroyed = false;
}
