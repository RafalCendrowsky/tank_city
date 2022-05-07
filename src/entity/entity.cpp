#include "entity.h"

void EntityIterator::add(Entity *entity) {
    entities.push_back(entity);
}

void EntityIterator::remove(Entity *entity) {
    int i = 0;
    for (auto entityI: entities) {
        if (entityI == entity) {
            entities.erase(entities.begin() + i);
        }
        i++;
    }
}



Entity::Entity(const sf::Image& image, sf::Vector2f position) {
    if (!texture.loadFromImage(image))
        throw std::invalid_argument("Invalid image for texture");
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2<float> {texture.getSize().x / 2.f, texture.getSize().y / 2.f});
}

bool Entity::isDestroyed() const {
    return destroyed;
}

void Entity::destroy() {
    destroyed = true;
}

double Entity::getSpeed() const {
    return speed;
};

void Entity::setSpeed(double speed) {
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

void Entity::move(Entity::eDirection direction)
{
    b2Vec2 velocity(0, 0);
    rotate(direction);
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

sf::Sprite Entity::getSprite() const {
    return sprite;
}

b2Body* Entity::getBody() {
    return body;
}

void Entity::update() {
    sf::Vector2<float> position {body->GetPosition().x * SCALE, body->GetPosition().y * SCALE};
    sprite.setPosition(position);
}

void Entity::rotate(Entity::eDirection direction) {
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

Entity::Entity(const sf::Image &image, sf::Vector2f position) {

}
