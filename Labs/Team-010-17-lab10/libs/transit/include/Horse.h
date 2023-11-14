#ifndef HORSE_H_
#define HORSE_H_

#include <vector>
#include <random>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @class Horse
 * @brief Represents a horse in a physical system
*/
class Horse : public IEntity {
 public:
    /**
     * @brief Horses are constructed
     * @param obj JsonObject containing information about the horse
    */
    Horse(JsonObject& obj);

    /**
     * @brief Destructor
    */
    ~Horse();

    /**
      * @brief Gets the next random destination
      */
    void getNextRandom();

    /**
     * @brief Moves the horse to a random destination
     * @param dt Delta time
    */
    void update(double dt);

 private:
    IStrategy* toDestination = nullptr;
    bool available = true;
};

#endif
