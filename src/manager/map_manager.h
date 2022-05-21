#pragma once
#include "base_manager.h"
#include "../entity/entity.h"

class MapManager: public BaseManager<Entity> {
public:
    MapManager(sf::RenderWindow& window, EntityIterator* iterator);
    void createMap(int level);

    void createIndestructibleWall(const sf::Image& image, sf::Vector2<float> position);

    void createWall(const sf::Image &image, sf::Vector2<float> position);
};