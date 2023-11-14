#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

#include "PathStrategy.h"
#include "transit/include/math/vector3.h"

/**
 * @brief DfsStrategy creates a strategy using Depth First Search
 */
class DfsStrategy : public PathStrategy {
 public:
  /**
   * @brief Constructs a DFS strategy
   * @param start A Vector3 containing the start location
   * @param destination A Vector3 containing the destination
   * @param graph A pointer to an IGraph
   * @return No return
   */
  DfsStrategy(Vector3 start, Vector3 destination, const routing::IGraph* graph);
};

#endif
