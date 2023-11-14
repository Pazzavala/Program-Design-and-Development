#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

/**
   * @brief Abstract representation of an entity
  **/
class IEntity {
 public:
  /**
   * @brief Constructs an entity
   * @param none
   * @return No return
  **/
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief Deallocates an entity
   * @param none
   * @return No return
  **/
  virtual ~IEntity() { delete graph; }
  /**
   * @brief Gets the ID of the entity
   * @param none
   * @return An integer containing the id of the entity
  **/
  virtual int GetId() const { return id; }
  /**
   * @brief Gets the position of the entity
   * @param none
   * @return A Vector3 object containing the position of the entity
  **/
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Gets the direction of the entity
   * @param none
   * @return A Vector3 object containing direction of the entity
  **/
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Gets the destination of the entity
   * @param none
   * @return A Vector3 object containing the destination of the entity
  **/
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Gets the details of the entity
   * @param none
   * @return Details of the entity
  **/
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Gets the color of the entity
   * @param none
   * @return A string containing the color of the entity
  **/
  virtual std::string GetColor() const { return "None"; }
  /**
   * @brief Gets the speed of the entity
   * @param none
   * @return A float containing the speed of the entity
  **/
  virtual float GetSpeed() const = 0;
  /**
   * @brief Gets the availability of the entity
   * @param none
   * @return A boolean indicating the entity's availability
  **/
  virtual bool GetAvailability() const {}
  /**
   * @brief Sets the availability of the entity
   * @param choice A boolean indicating the entity's availability
   * @return No return
  **/
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Updates the entity's position
   * @param dt A double containing the entity's direction
   * @param scheduler A vector of entities
   * @return No return
  **/
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Sets the graph of the entity
   * @param graph A graph
   * @return No return
  **/
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Sets the position of the entity
   * @param pos_ A Vector3 object containing the entity's new position
   * @return No return
  **/
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Sets the direction of the entity
   * @param dir_ A Vector3 object containing the entity's new direction
   * @return No return
  **/
  virtual void SetDirection(Vector3 dir_) {}
  /**
   * @brief Sets the destination of the entity
   * @param des_ A Vector3 object containing the entity's new destination
   * @return No return
  **/
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Sets the color of the entity
   * @param col_ A string containing the entity's new color
   * @return No return
  **/
  virtual void SetColor(std::string col_) {}
  /**
   * @brief Rotates the entity
   * @param angle A double containing the rotation angle
   * @return No return
  **/
  virtual void Rotate(double angle) {}
  /**
   * @brief Moves the entity up
   * @param height A double containing a distance
   * @return No return
  **/
  virtual void Jump(double height) {}

 protected:
  int id;
  const IGraph* graph;
};

#endif
