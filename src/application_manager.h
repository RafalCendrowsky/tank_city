#include <vector>
#include <SFML/Graphics.hpp>
#include <box2d/b2_world.h>
#include "./entity/entity.h"
#include "./game_manager.h"


class ApplicationManager{

    private:
        b2World world;
        sf::RenderWindow window;
        std::vector<Entity> entities;
        GameManager gameManager;

        void update();
        void render();
        void handleEvents();
        void onKeyPress(int key);
};