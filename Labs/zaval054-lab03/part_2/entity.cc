#include "entity.h"

const std::string& Entity::GetName() {
  return name;
}

std::vector<double> Entity::GetPosition() {
  return position;
}

void Entity::SetPosition(double num) {
  position.push_back(num);
}