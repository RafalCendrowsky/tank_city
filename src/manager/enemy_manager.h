#pragma once
#include "base_manager.h"
#include "../entity/enemy_tank.h"

class EnemyManager: public BaseManager<EnemyTank> {
public:
    EnemyManager(sf::RenderWindow& window, EntityIterator* iterator, BaseManager<Bullet>& bulletManager);
    void act();
    void clear();
private:
    BaseManager<Bullet> &bulletManager;
};
