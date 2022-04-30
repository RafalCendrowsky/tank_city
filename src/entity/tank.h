#pragma once
#include "entity.h"
#include "bullet.h"

class Tank: public Entity {
public:
    enum e_direction {RIGHT = 0, LEFT = 1, TOP = 2, BOTTOM = 3};
    void update();
    void move(e_direction direction);
    void stop();
private:
    double speed;
    int hp;
};