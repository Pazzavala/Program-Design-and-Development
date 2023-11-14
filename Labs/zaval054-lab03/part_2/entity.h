#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <vector>
// Entity is the base class for any simulation object
class Entity {
 public:
 // Constructor
  Entity(const std::string& name = "Entity"): name(name) {};
  // Destructor
  virtual ~Entity() {};
  // Returns the name of the entity
  const std::string& GetName();
  // Returns the position of the entity in space
  std::vector<double> GetPosition();
  // set the position of items
  void SetPosition(double num);
    
  protected:
    const std::string name;
    std::vector<double> position;
};

// An entity that can move and be updated
class MovableEntity : public Entity {
 public:
  // Constructor
  MovableEntity(const std::string& name = "Entity"): Entity(name) {};
  // Destructor
  ~MovableEntity() override {};
  // Updates the movable entity
  virtual void Update(double dt){};
};

#endif