#ifndef ROBOTFACTORY_H_
#define ROBOTFACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief Represents a concrete factory for a robot.
 */
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates a new entity for the robot factory.
   * @param obj A reference to a JsonObject containing details for robot object.
   * @return A robot entity object.
   **/
  IEntity* CreateEntity(JsonObject& obj) override;
};

#endif
