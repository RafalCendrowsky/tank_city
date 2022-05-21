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
    mapManager->createIndestructibleWall(boundaryImage, sf::Vector2{size.x / 50, size.y / 2});
    mapManager->createIndestructibleWall(boundaryImage, sf::Vector2{size.x * 49 / 50, size.y / 2});
    mapManager->createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y / 30});
    mapManager->createIndestructibleWall(boundaryImageRotated, sf::Vector2{size.x / 2, size.y * 29 / 30});
    float x = size.x/7;
    float y = size.x/14;
    mapManager->createWall(wallImage, sf::Vector2 {x+100.f, y+100.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+100.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+100.f, y+240.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+100.f, y+555.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+100.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+100.f, y+695.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+275.f, y+100.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+275.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+275.f, y+240.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+275.f, y+555.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+275.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+275.f, y+695.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+450.f, y+100.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+450.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+450.f, y+240.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+450.f, y+555.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+450.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+450.f, y+695.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+1290.f, y+100.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1290.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1290.f, y+240.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1290.f, y+555.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1290.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1290.f, y+695.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+1115.f, y+100.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1115.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1115.f, y+240.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1115.f, y+555.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1115.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1115.f, y+695.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+940.f, y+100.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+940.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+940.f, y+240.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+940.f, y+555.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+940.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+940.f, y+695.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+30.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+100.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+170.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+240.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+310.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+380.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+450.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+520.f, y+400.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+870.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+940.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1010.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1080.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1150.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1220.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1290.f, y+400.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+1360.f, y+400.f});


    mapManager->createWall(wallImage, sf::Vector2 {x+520.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+590.f, y+625.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+800.f, y+625.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+870.f, y+625.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+520.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+590.f, y+170.f});

    mapManager->createWall(wallImage, sf::Vector2 {x+800.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+870.f, y+170.f});


    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+100.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+170.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+240.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+310.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+380.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+450.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+485.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+555.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+625.f});


    mapManager->createWall(wallImage, sf::Vector2 {x+625.f, y+818.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+765.f, y+818.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+625.f, y+748.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+765.f, y+748.f});
    mapManager->createWall(wallImage, sf::Vector2 {x+695.f, y+748.f});

    }