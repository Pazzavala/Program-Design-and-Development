#define _USE_MATH_DEFINES
#include "Drone.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "BfsStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "Package.h"
#include "PathStrategy.h"
#include "SimulationModel.h"

Drone::Drone(JsonObject& obj) : IEntity(obj) { available = true; }

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

      if (!pickedUp) {
        // Set Beeline to pickup package
        Vector3 currentPosition = this->getPosition();
        this->setStrategy(
            new BeelineStrategy(currentPosition, packagePosition));

        if (currentPosition.dist(packagePosition) <= 0.00001)
          pickedUp = true;
      }

      if (pickedUp) {
        // Use package startegy
        std::string strategyName = package->getStrategyName();

        if (strategyName == "astar") {
          this->setStrategy(new AstarStrategy(packagePosition, finalDestination,
                                              model->getGraph()));
        } else if (strategyName == "dfs") {
          this->setStrategy(new DfsStrategy(packagePosition, finalDestination,
                                            model->getGraph()));
        } else if (strategyName == "bfs") {
          this->setStrategy(new BfsStrategy(packagePosition, finalDestination,
                                            model->getGraph()));
        } else if (strategyName == "dijkstra") {
          this->setStrategy(new DijkstraStrategy(
              packagePosition, finalDestination, model->getGraph()));
        }

        if (strategy->isCompleted()) {
          available = true;
          package->handOff();
        }
      }
    }
  }
}

void Drone::update(double dt) {
  if (available) {
    getNextDelivery();
  } else {
    // There is a package available
    this->UseStrategy(this, dt);
  }
}

void Drone::setStrategy(PathStrategy* strategy) {
  // delete this->strategy;  // Do i need this?
  this->strategy = strategy;
}

void Drone::UseStrategy(IEntity* entity, double dt) const {
  this->strategy->move(entity, dt);
}
