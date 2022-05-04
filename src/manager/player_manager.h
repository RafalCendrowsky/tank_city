#pragma once
#include "../entity/player_tank.h"

class PlayerManager {
public:
    PlayerManager(sf::RenderWindow& window, sf::Vector2<float> spawnPosition, b2World& world);
    void render();
    void update();
    void movePlayer(Entity::eDirection direction);
    void stopPlayer();
    void playerShoot();
    void removeBullet();
private:
    sf::RenderWindow& window;
    std::unique_ptr<PlayerTank> playerPtr;
    std::shared_ptr<Bullet> bulletPtr;
    b2World& world;
    sf::Vector2<float> spawnPosition;
};