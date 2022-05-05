#pragma once

#include <box2d/b2_world_callbacks.h>

class ContactListener : public b2ContactListener {
public:
    void ContactListener::BeginContact(b2Contact *contact);
};