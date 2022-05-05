#pragma once
#include "base_manager.h"
#include "../entity/enemy_tank.h"

class EnemyManager: public BaseManager<EnemyTank> {
public:
    EnemyManager(sf::RenderWindow& window, b2World& world, BaseManager<Bullet>& bulletManager);
    void act();
private:
    BaseManager<Bullet> &bulletManager;
};
