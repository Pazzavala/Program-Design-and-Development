#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

#include "PathStrategy.h"
#include "graph.h"
#include "transit/include/math/vector3.h"

/**
 * @brief AstarStrategy creates a strategy using A*
 */
class AstarStrategy : public PathStrategy {
 public:
  /**
   * @brief Constructs a A* strategy
   * @param start A Vector3 containing the start location
   * @param destination A Vector3 containing the destination
   * @param graph A pointer to an IGraph
   * @return No return
   */
  AstarStrategy(Vector3 start, Vector3 destination,
                const routing::IGraph* graph);
};

#endif
