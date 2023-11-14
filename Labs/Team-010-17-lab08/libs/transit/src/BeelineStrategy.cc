#include "BeelineStrategy.h"

#include "transit/include/math/vector3.h"

BeelineStrategy::BeelineStrategy(Vector3 start, Vector3 destination)
    : PathStrategy() {
  std::vector<float> startVector;
  std::vector<float> destinationVector;
  startVector.push_back(start[0]);
  startVector.push_back(start[1]);
  startVector.push_back(start[2]);

  destinationVector.push_back(destination[0]);
  destinationVector.push_back(destination[1]);
  destinationVector.push_back(destination[2]);

  path.push_back(startVector);
  path.push_back(destinationVector);
  this->index = 0;
}
