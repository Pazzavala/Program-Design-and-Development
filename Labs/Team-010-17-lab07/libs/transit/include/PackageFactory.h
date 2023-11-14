#ifndef PACKAGEFACTORY_H_
#define PACKAGEFACTORY_H_

#include "IEntityFactory.h"

/**
 * @brief Represents a concrete factory for a package.
 */
class PackageFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates a new entity for the package factory.
   * @param obj A reference to a JsonObject containing details for package
   *object.
   * @return A package entity object.
   **/
  IEntity* CreateEntity(JsonObject& obj) override;
};

#endif
