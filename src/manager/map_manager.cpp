#include "map_manager.h"
#include "../entity/indestructiblewall.h"
#include "../entity/wall.h"
#include "../resources/map1.cpp"
#include "../resources/map2.cpp"


MapManager::MapManager(sf::RenderWindow &window, EntityIterator* iterator) : BaseManager(window, iterator) {
}

void MapManager::createMap(int level) {
    switch (level)
    {
    case 1:
        crateMap1(window, this);
        break;
    case 2:
        crateMap2(window, this);
        break;

    default:
        break;
    }
}

void MapManager::createIndestructibleWall(const sf::Image& image, sf::Vector2<float> position) {
    std::shared_ptr<Entity> wallPtr(new IndestructibleWall(image, position, iterator));
    entities.push_back(wallPtr);
}

void MapManager::createWall(const sf::Image& image, sf::Vector2<float> position) {
    std::shared_ptr<Entity> wallPtr(new Wall(image, position, iterator));
    entities.push_back(wallPtr);
}
