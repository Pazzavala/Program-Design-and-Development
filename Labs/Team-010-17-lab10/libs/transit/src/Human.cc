#include "Human.h"

#include "AstarStrategy.h"
#include "SimulationModel.h"

Human::Human(JsonObject& obj) : IEntity(obj) {}

Human::~Human() {}

void Human::getNextRandom() {
    // bounds
    double x_lower = -1400;
    double x_upper = 1500;
    double y_lower = 240;
    double y_upper = 300;
    double z_lower = -800;
    double z_upper = 800;

    available = false;

    // random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // generate random values within bounds
    std::uniform_real_distribution<double> x_dist(x_lower, x_upper);
    std::uniform_real_distribution<double> y_dist(y_lower, y_upper);
    std::uniform_real_distribution<double> z_dist(z_lower, z_upper);

    double x = x_dist(gen);
    double y = y_dist(gen);
    double z = z_dist(gen);

    Vector3 destination(x, y, z);

    toDestination = new AstarStrategy(position, destination, model->getGraph());
}

void Human::update(double dt) {
    if (available) {
        getNextRandom();
    }
    if (toDestination) {
        toDestination->move(this, dt);

        if (toDestination->isCompleted()) {
            delete toDestination;
            toDestination = nullptr;
            available = true;
        }
    }
}
