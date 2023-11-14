#ifndef HORSE_FACTORY_H_
#define HORSE_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Horse.h"

/**
 *@brief Horse Factory to produce Horses class.
 **/
class HorseFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for HorseFactory class.
   **/
  virtual ~HorseFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
