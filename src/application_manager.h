#include <vector>
#include <SFML/Graphics.hpp>
#include <box2d/b2_world.h>
#include "./entity/entity.h"
#include "./game_manager.h"


class ApplicationManager{
public:
    void run();
private:
    b2World world = b2World(b2Vec2 {0.0f, 0.0f});
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 600), "Battle City");
    std::vector<Entity*> entities;
    GameManager gameManager;
    const float timestep = 1.0/60.0;
    const int32 velocityIterations = 8;
    const int32 positionIterations = 3;
    int currentKey;
    void update();
    void render();
    void handleEvents();
    void onKeyPress(int key);
};