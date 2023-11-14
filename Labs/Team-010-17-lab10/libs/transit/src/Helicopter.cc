#include "Helicopter.h"
#include <iostream>

Helicopter::Helicopter(JsonObject& obj) : IEntity(obj) {}

Helicopter::~Helicopter() {}

void Helicopter::GetRandom() {
    // bounds
    double x_lower = -1400;
    double x_upper = 1500;
    double y_lower = 240;
    double y_upper = 600;
    double z_lower = -800;
    double z_upper = 800;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<double> unif_x(x_lower, x_upper);
    std::uniform_real_distribution<double> unif_y(y_lower, y_upper);
    std::uniform_real_distribution<double> unif_z(z_lower, z_upper);

    double x = unif_x(gen);
    double y = unif_y(gen);
    double z = unif_z(gen);

    available = false;

    Vector3 destination(x, y, z);

    toDestination = new BeelineStrategy(position, destination);
}

void Helicopter::update(double dt) {
    if (available) {
        GetRandom();
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
