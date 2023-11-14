#ifndef HELICOPTER_H_
#define HELICOPTER_H_

#include <vector>
#include <random>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "BeelineStrategy.h"

/**
 * @class Helicopter
 * @brief Represents a helicopter in a physical system
*/
class Helicopter : public IEntity {
 public:
    /**
     * @brief Helicopters are constructed
     * @param obj JsonObject containing information about the helicopter
    */
    Helicopter(JsonObject& obj);

    /**
     * @brief Destructor
    */
    ~Helicopter();

    /**
     * @brief Gets next random destination
    */
    void GetRandom();

    /**
     * @brief Moves the helicopter to a random destination
     * @param dt Delta time
    */
    void update(double dt);

 private:
    IStrategy* toDestination = nullptr;
    bool available = true;
};

#endif
