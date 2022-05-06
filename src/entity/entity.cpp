#include "entity.h"
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

float Entity::SCALE = 100.f;

Entity::Entity(const sf::Image& image, sf::Vector2f position, b2World &world) {
    if (!texture.loadFromImage(image))
        throw std::invalid_argument("Invalid image for texture");

    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2<float> {static_cast<float>(texture.getSize().x) / 2, (float)(texture.getSize().y) / 2});

    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x / SCALE, position.y / SCALE);
    bodyDef.type = b2_dynamicBody;
    body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(texture.getSize().x / (SCALE * 2) , texture.getSize().y / (SCALE * 2));
    body->CreateFixture(&dynamicBox, 1.0f);

    body->GetUserData().pointer = (uintptr_t)(this);
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}

bool Entity::isDestroyed() const {
    return destroyed;
}

void Entity::update() {
    sf::Vector2<float> position {body->GetPosition().x * SCALE, body->GetPosition().y * SCALE};
    sprite.setPosition(position);
}

void Entity::destroy() {
    destroyed = true;
}

b2Body* Entity::getBody() {
    return body;
}

bool Entity::isBullet() const {
    return bullet;
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
