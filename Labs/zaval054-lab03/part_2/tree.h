#ifndef TREE_H_
#define TREE_H_

#include "entity.h"

// Represents a Tree in a physical system
class Tree : public Entity {
 public:
  // Trees are on the ground, so do not have a z component
  Tree(const std::string& name, double x, double y);
  // Destructor
  ~Tree() override;
};

#endif
