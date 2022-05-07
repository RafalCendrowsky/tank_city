#include "map_manager.h"
#include "../src/entity/indestructiblewall.h"
#include "../src/entity/wall.h"
#include <box2d/b2_weld_joint.h>

MapManager::MapManager(sf::RenderWindow &window, b2World &world) : BaseManager(window, world) {
}

void MapManager::createMap() {
    sf::Image boundaryImage;
    boundaryImage.loadFromFile("src/resources/boundary.png");
    sf::Image boundaryImageRotated;
    boundaryImageRotated.loadFromFile("src/resources/boundary_rotated.png");
    sf::Image wallImage;
    wallImage.loadFromFile("src/resources/wall.png");
    auto size = window.getView().getSize();
    createIndestructibleWall(boundaryImage, sf::Vector2{size.x / 30, size.y / 2});
    createIndestructibleWall(boundaryImage, sf::Vector2{size.x * 29 / 30, size.y / 2});
    createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y / 20});
    createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y * 19 / 20});
    createWall(wallImage, sf::Vector2 {400.f, 400.f});
    createWall(wallImage, sf::Vector2 {400.f, 450.f});
    createWall(wallImage, sf::Vector2 {400.f, 500.f});
    createWall(wallImage, sf::Vector2 {400.f, 550.f});
    createWall(wallImage, sf::Vector2 {400.f, 600.f});
    createWall(wallImage, sf::Vector2 {400.f, 650.f});
    createWall(wallImage, sf::Vector2 {400.f, 700.f});
}

void MapManager::createIndestructibleWall(const sf::Image& image, sf::Vector2<float> position) {
    std::shared_ptr<Entity> wallPtr(new IndestructibleWall(image, position, world));
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

void MapManager::createWall(const sf::Image& image, sf::Vector2<float> position) {
    std::shared_ptr<Entity> wallPtr(new Wall(image, position, world));
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
