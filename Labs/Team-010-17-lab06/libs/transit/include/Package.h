#ifndef PACKAGE_H
#define PACKAGE_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 * @brief Class representing a package in the simulation.
*/
class Package : public IEntity {
 public:
  /**
   * @brief Constructor that creates a Package object.
  */
  Package(JsonObject& obj);

  ~Package() override = default;

  /**
   * @brief Get the package's position.
   * 
   * @return Position of the package.
  */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Get the diection of the package.
   * 
   * @return Direction of the package.
  */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Get the package's destination
   * 
   * @return Destination of the package.
  */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Get the package's availability.
   * 
   * @return Availability status of the package.
  */
  bool GetAvailability() const { return available; }

  /**
   * @brief Gets the package's details.
   * 
   * @return Details of the package object.
  */
  JsonObject GetDetails() const override;

  /**
   * @brief Gets the package's speed.
   * 
   * @return Speed value of the package.
  */
  float GetSpeed() const { return speed; }

  /**
   * @brief Sets the package's availability.
   * 
   * @param choice the availability of the package.
  */
  void SetAvailability(bool choice);

  /**
   * @brief Sets the package's position.
   * 
   * @param pos_ the package's coordinates.
  */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the package's direction.
   * 
   * @param dir_ the direction's coordinates.
  */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the package's destination.
   * 
   * @param des_ the destination's coordinates.
  */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Rotates a package.
   * 
   * @param angle reprsenting the degrees of rotation.
  */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // PACKAGE_H
