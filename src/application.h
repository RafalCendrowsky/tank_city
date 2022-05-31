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
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1600,900), "Battle City", sf::Style::Default);
    PlayerManager playerManager = PlayerManager(window, sf::Vector2<float> {800 - 7*70, 450+5*70.f}, &iterator);
    BaseManager<Bullet> bulletManager = BaseManager<Bullet>(window, &iterator);
    EnemyManager enemyManager = EnemyManager(window, &iterator, bulletManager);
    MapManager mapManager = MapManager(window, &iterator);
    TargetManager targetManager = TargetManager(window, sf::Vector2<float> {800, 450+5*70.f}, &iterator);
    const float timeStep = 1.0 / 60.0;
    int currentKey;
    void update();
    void render();
    void handleEvents();
    void onKeyPress(int key);
};
