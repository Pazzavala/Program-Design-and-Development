#ifndef PATH_STRATEGY_H_
#define PATH_STRATEGY_H_

#include <string>
#include <vector>

#include "IStrategy.h"
#include "graph.h"

/**
 * @brief PathStrategy implements IStrategy
 */
class PathStrategy : public IStrategy {
 public:
  /**
   * @brief Constructs a path strategy using a default constructor
   */
  PathStrategy();

  /**
   * @brief Constructs a path strategy based on a path
   * @param path A vector of vectors of floats representing a path on the map
   * @return no return
   */
  PathStrategy(std::vector<std::vector<float>> path);

  /**
   * @brief Moves an entity
   * @param entity A pointer to the IEntity object to be moved
   * @param dt A double representing a different in time
   * @return No return
   */
  void move(IEntity* entity, double dt);
  /**
   * @brief Denotes a successful arrival to the final destination
   * @param None
   * @return True if the arrival was successful, false if not
   */
  bool isCompleted();

 protected:
  std::vector<std::vector<float>> path;
  int index;
};

#endif
