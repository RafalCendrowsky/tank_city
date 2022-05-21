#pragma once
#include "../entity/target.h"

class TargetManager {
public:
    TargetManager(sf::RenderWindow& window,  sf::Vector2<float> spawnPosition, EntityIterator* iterator);
    void render();
    void update();
private:
    sf::RenderWindow& window;
    std::unique_ptr<Target> targetPtr;
    EntityIterator* iterator;
    sf::Vector2<float> spawnPosition;
};

