#ifndef DRONE_H_
#define DRONE_H_
#include "entity.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Drone : public MovableEntity {
 public:
  // Drones are created with a name
  Drone(const std::string& name);
  // Destructor
  ~Drone() override;
  // Updates the drone's position
  void Update(double dt) override;
  // Sets the drone's velocity
  void SetVelocity(std::vector<double> velocity);
  // Rotates a drone
  void Rotate(double angle);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  Drone(const Drone& drone) = delete;
  // {
  //   std::string name = drone.name;
  //   std::vector<double> position = drone.position;
  //   std::vector<double> velocity =  drone.velocity;
  // }

  Drone& operator=(const Drone& drone) = delete; 
  // {
  //   return *this;
  // }

 private:
  std::vector<double> velocity;
};

#endif