#include <vector>
#include <SFML/Graphics.hpp>
#include <box2d/b2_world.h>
#include "../entity/entity.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "map_manager.h"
#include "../contact_listener.h"


class ApplicationManager{
public:
    void run();
private:
    b2World world = b2World(b2Vec2 {0.0f, 0.0f});
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(), "Battle City", sf::Style::Fullscreen);
    PlayerManager playerManager = PlayerManager(window, sf::Vector2<float> {300.f, 300.f}, world);
    BaseManager<Bullet> bulletManager = BaseManager<Bullet>(window, world);
    EnemyManager enemyManager = EnemyManager(window, world, bulletManager);
    MapManager mapManager = MapManager(window, world);
    ContactListener contactListener;
    const float timeStep = 1.0 / 60.0;
    const int32 velocityIterations = 8;
    const int32 positionIterations = 3;
    int currentKey;
    void update();
    void render();
    void handleEvents();
    void onKeyPress(int key);
};