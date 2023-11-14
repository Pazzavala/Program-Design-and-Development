#define _USE_MATH_DEFINES
#include "robot.h"

#include <cmath>

Robot::Robot(const std::string& name, double radius) : MovableEntity(name), angle(0.0), radius(radius) {
  SetPosition(radius * std::cos(angle));
  SetPosition(radius * std::sin(angle));

}

Robot::~Robot() {

}

void Robot::Update(double dt) {
  angle += dt;
  position.at(0) = radius * std::cos(angle);
  position.at(1) = radius * std::sin(angle);
}
