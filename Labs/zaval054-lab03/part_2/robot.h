#ifndef ROBOT_H_
#define ROBOT_H_
#include "entity.h"

// Represents a robot in a physical system.
// Robots move in a circle with a specified radius.
class Robot : public MovableEntity {
 public:
  // Robots are declared with a name and a radius
  Robot(const std::string& name, double radius);
  // Destructor
  ~Robot() override;
  // Updates the robot's position
  void Update(double dt) override;

 private:
  double angle;
  double radius;
};

#endif