#ifndef COMPOSITEFACTORY_H_
#define COMPOSITEFACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief Represents a composite factory
 **/
class CompositeFactory {
 private:
  std::vector<IEntityFactory*> componentFactories;

 public:
  /**
   * @brief Creates a new entity
   * @param obj A reference to a JsonObject
   * @return A pointer to an IEntity
   **/
  IEntity* CreateEntity(JsonObject& obj);
  /**
   * @brief Adds a factory to componentFactories
   * @param fact A pointer to an IEntityFactory
   * @return no return
   **/
  void AddFactory(IEntityFactory* fact);
};

#endif
