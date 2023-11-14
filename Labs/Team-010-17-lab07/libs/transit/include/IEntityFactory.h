#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include "IEntity.h"
#include "util/json.h"

/**
 * @brief Represents an IEntity Factory
 **/
class IEntityFactory {
 public:
  /**
   * @brief Creates a new entity
   * @param obj A reference to a JsonObject
   * @return A pointer to an IEntity
   **/
  virtual IEntity* CreateEntity(JsonObject& obj) = 0;
};
#endif
