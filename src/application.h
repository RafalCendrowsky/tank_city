#include <vector>
#include <SFML/Graphics.hpp>
#include "entity/entity.h"
#include "manager/player_manager.h"
#include "manager/enemy_manager.h"
#include "manager/map_manager.h"
#include "manager/target_manager.h"


class Application{
public:
    void run();
private:
    EntityIterator iterator;
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(sf::Vector2u(1920, 1080)), "Battle City", 0);
    PlayerManager playerManager = PlayerManager(window, sf::Vector2<float> {400.f, 900.f}, &iterator);
    BaseManager<Bullet> bulletManager = BaseManager<Bullet>(window, &iterator);
    EnemyManager enemyManager = EnemyManager(window, &iterator, bulletManager);
    MapManager mapManager = MapManager(window, &iterator);
    TargetManager targetManager = TargetManager(window, sf::Vector2<float> {969.f, 955.f}, &iterator);
    const float timeStep = 1.0 / 60.0;
    int currentKey;
    void update();
    void render();
    void handleEvents();
    void onKeyPress(int key);
};
