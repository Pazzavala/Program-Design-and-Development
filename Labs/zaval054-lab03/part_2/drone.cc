#define _USE_MATH_DEFINES
#include "drone.h"

#include <cmath>

Drone::Drone(const std::string& name) : MovableEntity(name) {
  // Drones have 3 components x,y,z
  // position = std::vector<double>(3);
  for (int i = 0; i < 3; i++) {
    SetPosition(0); 
  }
}

Drone::~Drone() {
  
}

void Drone::SetVelocity(std::vector<double> velocity) {
  // Copy the velocity data into the member variable array.
  for (double num: velocity)
    this->velocity.push_back(num);
}

void Drone::Update(double dt) {
  // Updates the drone position based on velocity and change in time
  for (int i = 0; i < position.size(); i++) {
    position.at(i) = position.at(i) + velocity.at(i) * dt;
  }
}

void Drone::Rotate(double angle) {
  // Rotates the drone by changing the velocity by a
  // specified angle.
  double x = velocity.at(0);
  double y = velocity.at(1);
  velocity.at(0) = x * std::cos(angle) - y * std::sin(angle);
  velocity.at(1) = x * std::sin(angle) + y * std::cos(angle);
}