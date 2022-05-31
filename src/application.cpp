#include <algorithm>
#include <iostream>
#include "application.h"

void Application::update()
{
    playerManager.update();
    bulletManager.update();
    enemyManager.update();
    mapManager.update();
    targetManager.update();
}

int Application::menu()
{
    window.clear(sf::Color::Black);
    sf::Font font;
    font.loadFromFile("src/resources/font.ttf");
    sf::Text title("Battle City", font, 100);
    title.setFillColor(sf::Color::Red);
    title.setStyle(sf::Text::Bold);
    title.setPosition(sf::Vector2<float>{300, 150});
    sf::Text newGameText("New Game", font, 50);
    newGameText.setFillColor(sf::Color::Magenta);
    newGameText.setPosition(sf::Vector2<float>{575, 350});
    sf::Text loadText("Load Game", font, 50);
    loadText.setFillColor(sf::Color::Magenta);
    loadText.setPosition(sf::Vector2<float>{550, 450});
    sf::Text quitText("Quit", font, 50);
    quitText.setFillColor(sf::Color::Magenta);
    quitText.setPosition(sf::Vector2<float>{700, 550});
    window.draw(title);
    window.draw(newGameText);
    window.draw(loadText);
    window.draw(quitText);

    window.display();
    while (handleEventsMenu() == 0)
    {

        switch (currentOption)
        {
        case newGame:
            newGameText.setStyle(sf::Text::Underlined);
            quitText.setStyle(sf::Text::Regular);
            loadText.setStyle(sf::Text::Regular);
            break;
        case load:
            loadText.setStyle(sf::Text::Underlined);
            quitText.setStyle(sf::Text::Regular);
            newGameText.setStyle(sf::Text::Regular);
            break;
        case quit:
            quitText.setStyle(sf::Text::Underlined);
            loadText.setStyle(sf::Text::Regular);
            newGameText.setStyle(sf::Text::Regular);
            break;
        default:
            break;
        }
        window.clear(sf::Color::Black);
        window.draw(title);
        window.draw(newGameText);
        window.draw(loadText);
        window.draw(quitText);
        window.display();
    }
    window.display();
    if (currentKey == load)
    {
        // read map and points from save
    }
    return 1;
}

void Application::run()
{
    window.setPosition(sf::Vector2i(0, 0));
    window.setKeyRepeatEnabled(false);
    int map = menu();
    mapManager.createMap(map);
    sf::Clock clock;
    sf::Clock enemyTimer;
    float accumulator = 0;
    while (window.isOpen())
    {
        if (enemyTimer.getElapsedTime().asSeconds() > 1.8)
        {
            enemyManager.act();
            enemyTimer.restart();
        }
        accumulator += clock.getElapsedTime().asSeconds();
        clock.restart();
        while (accumulator > timeStep)
        {
            update();
            // std::cout << accumulator << std::endl;
            accumulator -= timeStep;
        }
        handleEvents();
        render();
        window.display();
        while (clock.getElapsedTime().asSeconds() < timeStep)
        {
        }
    }
}

void Application::render()
{
    window.clear(sf::Color::Black);
    playerManager.render();
    bulletManager.render();
    enemyManager.render();
    mapManager.render();
    targetManager.render();
}

void Application::onKeyPress(int key)
{
    switch (key)
    {
    case sf::Keyboard::Left:
        currentKey = key;
        playerManager.movePlayer(Entity::eDirection::LEFT);
        break;
    case sf::Keyboard::Right:
        currentKey = key;
        playerManager.movePlayer(Entity::eDirection::RIGHT);
        break;
    case sf::Keyboard::Up:
        currentKey = key;
        playerManager.movePlayer(Entity::eDirection::UP);
        break;
    case sf::Keyboard::Down:
        currentKey = key;
        playerManager.movePlayer(Entity::eDirection::DOWN);
        break;
    case sf::Keyboard::Space:
        playerManager.playerShoot();
        break;
    case sf::Keyboard::Z:
        playerManager.removeBullet();
        break;
    case sf::Keyboard::Escape:
        this->window.close();
    default:
        break;
    }
}

void Application::handleEvents()
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            onKeyPress(event.key.code);
            break;
        case sf::Event::KeyReleased:
            if (currentKey == event.key.code)
            {
                playerManager.stopPlayer();
            }
            break;
        default:
            break;
        }
    }
}

int Application::handleEventsMenu()
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            return 3;
            break;
        case sf::Event::KeyPressed:
            return onKeyPressMenu(event.key.code);
            break;
        case sf::Event::KeyReleased:
            if (currentKey == event.key.code)
            {
                pressedKey = false;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

int Application::onKeyPressMenu(int key)
{
    if (pressedKey == false)
    {
        switch (key)
        {
        case sf::Keyboard::Up:
            currentKey = key;
            if (currentOption == newGame)
                currentOption = quit;
            else
                currentOption = static_cast<option>((currentOption - 1));
            pressedKey = true;
            break;
        case sf::Keyboard::Down:
            currentKey = key;
            currentOption = static_cast<option>((currentOption + 1) % (quit + 1));
            pressedKey = true;

            break;
        case sf::Keyboard::Space:
            switch (currentOption)
            {
            case newGame:
                return 1;
                break;
            case load:
                return 2;
                break;
            case quit:
                this->window.close();
                return 3;
                break;
            default:
                break;
            }
            break;
        case sf::Keyboard::Escape:
            this->window.close();
        default:
            break;
        }
    }
    return 0;
}