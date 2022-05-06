#include "map_manager.h"
#include <box2d/b2_weld_joint.h>

MapManager::MapManager(sf::RenderWindow &window, b2World &world) : BaseManager(window, world) {
}

void MapManager::createMap() {
    sf::Image image;
    image.loadFromFile("src/resources/boundary.png");
    sf::Image imageRotated;
    imageRotated.loadFromFile("src/resources/boundary_rotated.png");
    auto size = window.getView().getSize();
    createWall(image, sf::Vector2 {size.x / 30, size.y / 2});
    createWall(image, sf::Vector2 {size.x * 29 / 30, size.y / 2});
    createWall(imageRotated, sf::Vector2 {size.x / 2, size.y / 20});
    createWall(imageRotated, sf::Vector2 {size.x / 2, size.y * 19 / 20});
}

void MapManager::createWall(const sf::Image& image, sf::Vector2<float> position) {
    std::shared_ptr<Entity> wallPtr(new Entity(image, position, world));
    b2BodyDef bodyDef;
    bodyDef.position = b2Vec2 {position.x / Entity::SCALE, position.y / Entity::SCALE};
    bodyDef.type = b2_staticBody;
    b2Body* corner = world.CreateBody(&bodyDef);
    b2WeldJointDef jointDef;
    jointDef.bodyA = corner;
    jointDef.bodyB = wallPtr->getBody();
    auto* joint = (b2WeldJoint*) world.CreateJoint(&jointDef);
    entities.push_back(wallPtr);
    joints.push_back(joint);
}
