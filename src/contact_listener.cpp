#include "contact_listener.h"
#include "entity/entity.h"

void ContactListener::BeginContact(b2Contact *contact)
{
    auto entityA = (Entity *) (void *) contact->GetFixtureA()->GetBody()->GetUserData().pointer;
    auto entityB = (Entity *) (void *) contact->GetFixtureB()->GetBody()->GetUserData().pointer;
    if (entityA->getClassName() == "bullet" || entityB->getClassName() == "bullet") {
        entityA->destroy();
        entityB->destroy();
    }
    b2ContactListener::BeginContact(contact);
}