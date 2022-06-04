#include "catch.hpp"
#include "../src/entity/entity.h"

TEST_CASE("Entity tests")
{
    EntityIterator iterator;
    sf::Image image;
    image.loadFromFile("../src/resources/enemy_tank.png");
    std::shared_ptr<Entity> ent(new Entity(image, sf::Vector2<float> {0, 0}, &iterator));

    SECTION("constructor tests")
    {
        CHECK(ent->getDirection() == 2);
        CHECK(ent->getSpeed() == 0);
        CHECK(ent->getIterator() == &iterator);
        CHECK(ent->getSprite().getPosition() == sf::Vector2<float>{0,0});
        CHECK(ent->getSprite().getOrigin() == sf::Vector2<float>{30,30});
        CHECK(ent->getIterator()->entities[0] == ent.get());
        CHECK(ent->getClassName() == "entity");
        CHECK(ent->isDestroyed() == false);
    }

    SECTION("setters tests")
    {
        ent->setSpeed(12);
        CHECK(ent->getSpeed() == 12);
        ent->setDirection(Entity::eDirection::LEFT);
        CHECK(ent->getDirection() == 1);
    }
}
