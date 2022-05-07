#include "map_manager.h"
#include "../src/entity/indestructiblewall.h"
#include "../src/entity/wall.h"
#include <box2d/b2_weld_joint.h>

MapManager::MapManager(sf::RenderWindow &window, EntityIterator* iterator) : BaseManager(window, iterator) {
}

void MapManager::createMap() {
    sf::Image boundaryImage;
    boundaryImage.loadFromFile("src/resources/boundary.png");
    sf::Image boundaryImageRotated;
    boundaryImageRotated.loadFromFile("src/resources/boundary_rotated.png");
    sf::Image wallImage;
    wallImage.loadFromFile("src/resources/wall.png");
    auto size = window.getView().getSize();
    createIndestructibleWall(boundaryImage, sf::Vector2{size.x / 50, size.y / 2});
    createIndestructibleWall(boundaryImage, sf::Vector2{size.x * 49 / 50, size.y / 2});
    createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y / 30});
    createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y * 29 / 30});
    createWall(wallImage, sf::Vector2 {400.f, 400.f});
    createWall(wallImage, sf::Vector2 {400.f, 472.f});
    createWall(wallImage, sf::Vector2 {400.f, 544.f});
    createWall(wallImage, sf::Vector2 {400.f, 616.f});
    createWall(wallImage, sf::Vector2 {400.f, 688.f});
    createWall(wallImage, sf::Vector2 {400.f, 760.f});
    createWall(wallImage, sf::Vector2 {400.f, 830.f});
}

void MapManager::createIndestructibleWall(const sf::Image& image, sf::Vector2<float> position) {
    std::shared_ptr<Entity> wallPtr(new IndestructibleWall(image, position, iterator));
    entities.push_back(wallPtr);
}

void MapManager::createWall(const sf::Image& image, sf::Vector2<float> position) {
    std::shared_ptr<Entity> wallPtr(new Wall(image, position, iterator));
    entities.push_back(wallPtr);
}
