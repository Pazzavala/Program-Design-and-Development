#include "ICelebrationDecorator.h"

ICelebrationDecorator::ICelebrationDecorator(IStrategy* strategy)
    : strategy(strategy), celebrationTime(0) {}

void ICelebrationDecorator::move(IEntity *entity, double dt) {
    // If previous strategy done do current
    if (strategy->isCompleted()) {
        this->celebrate(entity, dt);
    } else {
        strategy->move(entity, dt);
    }
}

bool ICelebrationDecorator::isCompleted() {
    if (celebrationTime >= 4) {
        return true;
    } else {
        return false;
    }
}
