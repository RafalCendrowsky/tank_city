#include "enemy_manager.h"

EnemyManager::EnemyManager(sf::RenderWindow& window, b2World& world, BaseManager<Bullet>& bulletManager) :
        BaseManager<EnemyTank>(window, world), bulletManager(bulletManager) {}

void EnemyManager::act() {
    if (entities.size() < 2) {
        sf::Image image;
        image.loadFromFile("src/resources/tank.png");
        std::shared_ptr<EnemyTank> tank(new EnemyTank(image, sf::Vector2<float> {400.f, 400.f}, world));
        entities.push_back(tank);
    }
    for (auto enemy: entities) {
        auto direction = Entity::eDirection(rand() % 4);
        enemy->move(direction);
//        if(!enemy->hasShot()) {
//            bulletManager.add(enemy->shoot());
//        }
    }
}
