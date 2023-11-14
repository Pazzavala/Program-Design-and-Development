#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "PathStrategy.h"
#include "math/vector3.h"

class Package;

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @class Drone
 * @brief Represents a drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction.
 */
class Drone : public IEntity {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  Drone(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Drone();

  /**
   * @brief Gets the next delivery in the scheduler
   */
  void getNextDelivery();

  /**
   * @brief Updates the drone's position
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Removing the copy constructor operator
   * so that drones cannot be copied.
   */
  Drone(const Drone& drone) = delete;

  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied.
   */
  Drone& operator=(const Drone& drone) = delete;

  /**
   * @brief Setting up the path strategy the drone will be using.
   * @param strategy is the type of strategy to be used.
  */
  void setStrategy(PathStrategy* strategy);

  /**
   * @brief Using the path strategy that is currently set.
   * @param entity is the entity that will be using the set strategy.
   * @param dt is the change in time by which the entity moves.
  */
  void UseStrategy(IEntity* entity, double dt) const;

 private:
  bool available = false;
  bool pickedUp = false;
  Package* package = nullptr;

  // IDK if this goes here
  PathStrategy* strategy;
};

#endif
