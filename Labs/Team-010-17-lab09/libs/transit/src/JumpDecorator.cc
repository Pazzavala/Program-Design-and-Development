#include "JumpDecorator.h"
#include "math/vector3.h"
#include <unistd.h>


JumpDecorator::JumpDecorator(IStrategy* strategy)
    : ICelebrationDecorator(strategy) {
        maxHeight = 280.0;
        minHeight = 260.0;
}

JumpDecorator::~JumpDecorator() {
    delete this;
}

void JumpDecorator::celebrate(IEntity* entity, double dt) {
    // Get the entities current position
    Vector3 position = entity->getPosition();
    // Create a new vector that add/sub to the positions vector
    Vector3 yChange(0, 2, 0);

    // Change the entities heigh (y) value by some number
    // Only do this up to a certain max height
    if (position[1] < maxHeight && (celebrationTime % 2) != 0) {
        entity->setPosition(position + (yChange * dt * entity->getSpeed()));
        position = entity->getPosition();

        // Only increment counter till it has reached maxHeight
        if (position[1] >= maxHeight)
            celebrationTime++;
    }

    // Only do this up to a certain min height
    if (position[1] > minHeight && (celebrationTime % 2) == 0) {
        entity->setPosition(position - (yChange * dt * entity->getSpeed()));
        position = entity->getPosition();

        // Only increment counter till it has reached minHeight
        if (position[1] <= minHeight)
            celebrationTime++;
    }
}
