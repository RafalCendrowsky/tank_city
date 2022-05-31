#include "../manager/map_manager.h"
#include "../entity/indestructiblewall.h"
#include "../entity/wall.h"

void crateMap1(sf::RenderWindow &window, MapManager *mapManager){
    sf::Image boundaryImage;
    boundaryImage.loadFromFile("src/resources/boundary.png");
    sf::Image boundaryImageRotated;
    boundaryImageRotated.loadFromFile("src/resources/boundary_rotated.png");
    sf::Image wallImage;
    wallImage.loadFromFile("src/resources/wall.png");
    auto size = window.getView().getSize();
    mapManager->createIndestructibleWall(boundaryImage, sf::Vector2{size.x / 50-19.f, size.y / 2});
    mapManager->createIndestructibleWall(boundaryImage, sf::Vector2{size.x * 49 / 50   +19.f, size.y / 2});
    mapManager->createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y / 30-19.f});
    mapManager->createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y * 29 / 30+19.f});
    float x = size.x/2;
    float y = size.y/2;
    mapManager->createWall(wallImage, sf::Vector2 {x, y});


    mapManager->createWall(wallImage, sf::Vector2 {x+70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x+4*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x+5*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x+6*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x+7*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x+8*70.f, y});

    mapManager->createWall(wallImage, sf::Vector2 {x-70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x-4*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x-5*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x-6*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x-7*70.f, y});
    mapManager->createWall(wallImage, sf::Vector2 {x-8*70.f, y});


    mapManager->createWall(wallImage, sf::Vector2 {x, y+70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x, y+3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x, y+4*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x, y-70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x, y-3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x, y-4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x, y-5*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+3*70, y+4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+3*70, y+3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+3*70, y+2*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+6*70, y+4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+6*70, y+3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+6*70, y+2*70.f});


    mapManager->createWall(wallImage, sf::Vector2 {x+3*70, y-4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+3*70, y-3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+3*70, y-2*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+6*70, y-4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+6*70, y-3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+6*70, y-2*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x-3*70, y-4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-3*70, y-3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-3*70, y-2*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x-6*70, y-4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-6*70, y-3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-6*70, y-2*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x-3*70, y+4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-3*70, y+3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-3*70, y+2*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x-6*70, y+4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-6*70, y+3*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-6*70, y+2*70.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+70, y+5*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-70, y+5*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+70, y+4*70.f});
    mapManager->createWall(wallImage, sf::Vector2 {x-70, y+4*70.f});

    }