#pragma once
#include "base_manager.h"
#include "../entity/entity.h"

class MapManager: public BaseManager<Entity> {
public:
    MapManager(sf::RenderWindow& window, b2World& world);
    void createMap();
private:
    std::vector<b2Joint*> joints;
    void createWall(const sf::Image& image, sf::Vector2<float> position);
};