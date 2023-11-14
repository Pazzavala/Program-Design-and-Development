#include "SpinDecorator.h"

SpinDecorator::SpinDecorator(IStrategy* strategy)
    : ICelebrationDecorator(strategy) {}

SpinDecorator::~SpinDecorator() {
    delete this;
}

void SpinDecorator::celebrate(IEntity* entity, double dt) {
    entity->rotate(180 * entity->getSpeed() * dt);
    celebrationTime++;
}
