#ifndef DRONEFACTORY_H_
#define DRONEFACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief Represents a concrete factory for a drone.
 */
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates a new entity for the drone factory.
   * @param obj A reference to a JsonObject containing details for drone object.
   * @return A drone entity object.
   **/
  IEntity* CreateEntity(JsonObject& obj) override;
};

#endif
