#ifndef BEELINE_STRATEGY_H_
#define BEELINE_STRATEGY_H_

#include "PathStrategy.h"
#include "transit/include/math/vector3.h"

/**
 * @brief BeelineStrategy creates a strategy using the beeline method
 */
class BeelineStrategy : public PathStrategy {
 public:
  /**
   * @brief Constructs a beeline strategy
   * @param start A Vector3 containing the start location
   * @param destination A Vector3 containing the destination
   * @return No return
   */
  BeelineStrategy(Vector3 start, Vector3 destination);
};

#endif
