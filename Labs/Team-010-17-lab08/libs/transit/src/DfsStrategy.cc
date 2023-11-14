#include "DfsStrategy.h"

#include "routing/include/routing/depth_first_search.h"
#include "transit/include/math/vector3.h"

DfsStrategy::DfsStrategy(Vector3 start, Vector3 destination,
                         const routing::IGraph* graph)
    : PathStrategy() {
  std::vector<float> startVector;
  std::vector<float> destinationVector;
  startVector.push_back(start[0]);
  startVector.push_back(start[1]);
  startVector.push_back(start[2]);

  destinationVector.push_back(destination[0]);
  destinationVector.push_back(destination[1]);
  destinationVector.push_back(destination[2]);

  // Calculate Path using routing algortihms
  path = graph->GetPath(startVector, destinationVector,
                        routing::DepthFirstSearch::Default());
  this->index = 0;
}
