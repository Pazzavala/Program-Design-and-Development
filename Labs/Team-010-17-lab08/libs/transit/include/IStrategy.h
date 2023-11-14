#ifndef STRATEGY_H_
#define STRATEGY_H_

#include "IEntity.h"

/**
 * @brief IStrategy outlines a general strategy class
 */
class IStrategy {
 public:
  /**
   * @brief Moves an entity
   * @param entity A pointer to the IEntity object to be moved
   * @param dt A double representing a different in time
   * @return No return
   */
  void virtual move(IEntity* entity, double dt) = 0;
  /**
   * @brief Denotes a successful arrival to the final destination
   * @param None
   * @return True if the arrival was successful, false if not
   */
  bool virtual isCompleted() = 0;
};

#endif
