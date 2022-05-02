#include "entity.h"
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

Entity::Entity(const sf::Image& image, sf::Vector2f position, b2World &world) {
    if (!texture.loadFromImage(image))
        throw std::invalid_argument("Invalid image for texture");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(position);

    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.type = b2_dynamicBody;
    this->body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(image.getSize().x, image.getSize().y);
    this->body->CreateFixture(&dynamicBox, 1.0f);
}

sf::Sprite Entity::getSprite() const {
    return this->sprite;
}

bool Entity::isDestroyed() const {
    return this->destroyed;
}

void Entity::update() {
    sf::Vector2<float> position {this->body->GetPosition().x, this->body->GetPosition().y};
    this->sprite.setPosition(position);
}

void Entity::destroy() {
    this->destroyed = true;
}

b2Body* Entity::getBody() {
    return this->body;
}