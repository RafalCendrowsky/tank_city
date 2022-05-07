#include "enemy_manager.h"

EnemyManager::EnemyManager(sf::RenderWindow& window, EntityIterator* iterator, BaseManager<Bullet>& bulletManager) :
        BaseManager<EnemyTank>(window, iterator), bulletManager(bulletManager) {}

void EnemyManager::act() {
    if (entities.size() < 2) {
        sf::Image image;
        image.loadFromFile("src/resources/enemy_tank.png");
        std::shared_ptr<EnemyTank> tank(new EnemyTank(image, sf::Vector2<float> {400.f, 400.f}, iterator));
        entities.push_back(tank);
    }
    for (auto enemy: entities) {
        auto direction = Entity::eDirection(rand() % 4);
        enemy->move(direction);
        if(!enemy->hasShot()) {
            bulletManager.add(enemy->shoot());
        }
    }
}
