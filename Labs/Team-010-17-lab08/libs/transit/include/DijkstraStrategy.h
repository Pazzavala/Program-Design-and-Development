#ifndef DIJKSTRA_STRATEGY_H_
#define DIJKSTRA_STRATEGY_H_

#include "PathStrategy.h"
#include "transit/include/math/vector3.h"

/**
 * @brief DijkstraStrategy creates a strategy using Dijkstra's method
 */
class DijkstraStrategy : public PathStrategy {
 public:
  /**
   * @brief Constructs a Dijkstra strategy
   * @param start A Vector3 containing the start location
   * @param destination A Vector3 containing the destination
   * @param graph A pointer to an IGraph
   * @return No return
   */
  DijkstraStrategy(Vector3 start, Vector3 destination,
                   const routing::IGraph* graph);
};

#endif
