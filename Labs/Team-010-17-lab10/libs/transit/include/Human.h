#ifndef HUMAN_H_
#define HUMAN_H_

#include <vector>
#include <random>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @class Human
 * @brief Represents a human in a physical system
*/
class Human : public IEntity {
 public:
    /**
     * @brief Humans are constructed
     * @param obj JsonObject containing information about the human
    */
    Human(JsonObject& obj);

    /**
     * @brief Destructor
    */
    ~Human();

    /**
      * @brief Gets the next random destination
      */
    void getNextRandom();

    /**
     * @brief Moves the human to a random destination
     * @param dt Delta time
    */
    void update(double dt);

 private:
    IStrategy* toDestination = nullptr;
    bool available = true;
};

#endif
