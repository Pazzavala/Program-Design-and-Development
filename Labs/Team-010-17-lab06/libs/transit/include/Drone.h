#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @brief A representation of a drone
**/
class Drone : public IEntity {
 public:
  // Drones are created with a name
  /**
   * @brief Constructs a drone
   * @param obj Name of the drone
   * @return No return
  **/
  Drone(JsonObject& obj);
  // Destructor
  /**
   * @brief Deallocates a drone object
   * @param none
   * @return No return
  **/
  ~Drone();

  /**
   * @brief Speed of drone
   * @param none
   * @return Speed of the drone
  **/
  float GetSpeed() const { return speed; }

  // Gets the drone position
  /**
   * @brief Gets drone position
   * @param none
   * @return Position of the drone
  **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets drone direction
   * @param none
   * @return Direction of the drone
  **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets drone destination
   * @param none
   * @return Destination of the drone
  **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets drone color
   * @param none
   * @return Color of the drone
  **/
  std::string GetColor() const { return color; }

  /**
   * @brief Gets drone details
   * @param none
   * @return Details of the drone
  **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Gets drone availability
   * @param none
   * @return Availability of the drone
  **/
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets drone's nearest entity
   * @param scheduler A vector of entities
   * @return No return
  **/
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  // Updates the drone's position
  /**
   * @brief Updates drone's position
   * @param dt Drone's direction
   * @param scheduler A vector of entities
   * @return No return
  **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief Sets the drone's position
   * @param pos_ A Vector3 containing the new position
   * @return No return
  **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the drone's direction
  /**
   * @brief Sets the drone's direction
   * @param dir_ A Vector3 containing the new direction
   * @return No return
  **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the drone's destination
   * @param des_ A Vector3 containing the destination
   * @return No return
  **/
  void SetDestination(Vector3 des_) { destination = des_; }

  // Sets the drone's color
  /**
   * @brief Sets the drone's color
   * @param col_ A string with a color name
   * @return No return
  **/
  void SetColor(std::string col_) { color = col_; }

  // Rotates a drone
  /**
   * @brief Rotates a drone
   * @param angle A double containing the angle of rotation
   * @return No return
  **/
  void Rotate(double angle);

  /**
   * @brief Moves drone up
   * @param height A double containing a distance
   * @return No return
  **/
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be copied.
  /**
   * @brief Removes the copy constructor
   * @param drone Unchangeable Drone object
   * @return No return
  **/
  Drone(const Drone& drone) = delete;

  /**
   * @brief Removes the assignment operator
   * @param drone Unchangeable Drone object
   * @return No return
  **/
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  std::string color = "None";  // None means default color
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  IEntity* nearestEntity = NULL;
};

#endif
