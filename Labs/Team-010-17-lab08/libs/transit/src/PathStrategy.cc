#include "PathStrategy.h"

#include <string>
#include <vector>
#include "transit/include/math/vector3.h"


PathStrategy::PathStrategy() {}

PathStrategy::PathStrategy(std::vector<std::vector<float>> path) {
  this->path = path;
  this->index = 0;
}

void PathStrategy::move(IEntity* entity, double dt) {
  std::vector<float> destination = this->path.at(index);

  Vector3 destination_position(destination.at(0), destination.at(1),
                               destination.at(2));

  Vector3 current_position = entity->getPosition();
  Vector3 direction = (destination_position - current_position).unit();

  entity->setDirection(direction);
  entity->setPosition(entity->getPosition() +
                      (entity->getDirection() * entity->getSpeed() * dt));

  if (destination_position.dist(current_position) <= 0.00001)
    index++;
}

bool PathStrategy::isCompleted() {
  // Check if we are at the end of the path
  if (index == this->path.size() - 1)
    return true;
  else
    return false;
}
