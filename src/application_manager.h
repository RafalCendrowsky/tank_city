#include <vector>
#include <SFML/Graphics.hpp>
#include "entity.h"


class ApplicationManager{

    private:
        b2world world;
        sf::RenderWindow window;
        std::vector<Entity> entities;
        TankManager tankmanager;

        void update();
        void render();
        void handleEvents();
        void onKeyPress(int key);
};