#ifndef BFS_STRATEGY_H_
#define BFS_STRATEGY_H_

#include "PathStrategy.h"
#include "transit/include/math/vector3.h"

/**
 * @brief BfsStrategy creates a strategy using Breadth First Search
 */
class BfsStrategy : public PathStrategy {
 public:
  /**
   * @brief Constructs a BFS strategy
   * @param start A Vector3 containing the start location
   * @param destination A Vector3 containing the destination
   * @param graph A pointer to an IGraph
   * @return No return
   */
  BfsStrategy(Vector3 start, Vector3 destination, const routing::IGraph* graph);
};

#endif
