#include "enemy_manager.h"

EnemyManager::EnemyManager(sf::RenderWindow& window, EntityIterator* iterator, BaseManager<Bullet>& bulletManager) :
        BaseManager<EnemyTank>(window, iterator), bulletManager(bulletManager) {}

void EnemyManager::act() {
    if (entities.size() < 2) {
        sf::Image image;
        image.loadFromFile("src/resources/enemy_tank.png");
        std::shared_ptr<EnemyTank> tank(new EnemyTank(image, sf::Vector2<float> {800 + 7*70, 450-5*70.f}, iterator));
        std::shared_ptr<EnemyTank> tank2(new EnemyTank(image, sf::Vector2<float> {800 - 7*70, 450-5*70.f}, iterator));
        entities.push_back(tank);
        entities.push_back(tank2);
    }
    for (auto enemy: entities) {
        int randInt = rand() % 20;
        if (randInt < 6) {
            enemy->move(Entity::DOWN);
        } else if (randInt < 11) {
            enemy->move(Entity::LEFT);
        } else if (randInt < 16) {
            enemy->move(Entity::RIGHT);
        } else if (randInt < 18) {
            enemy->move(Entity::DOWN);
        }
        if(!enemy->hasShot()) {
            bulletManager.add(enemy->shoot());
        }
    }
}