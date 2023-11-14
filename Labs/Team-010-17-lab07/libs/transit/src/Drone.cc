#define _USE_MATH_DEFINES
#include "Drone.h"

#include <cmath>
#include <limits>

#include "Package.h"
#include "SimulationModel.h"

Drone::Drone(JsonObject& obj) : IEntity(obj) {
  available = true;
}

Drone::~Drone() {}

void Drone::getNextDelivery() {
  if (model && model->scheduledDeliveries.size() > 0) {
    package = model->scheduledDeliveries.front();
    model->scheduledDeliveries.pop_front();

    if (package) {
      available = false;
      pickedUp = false;

      Vector3 packagePosition = package->getPosition();
      Vector3 finalDestination = package->getDestination();
    }
  }
}

void Drone::update(double dt) {
  if (available)
    getNextDelivery();
}
