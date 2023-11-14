#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
/**
   * @brief Abstract controller class for transit
  **/
class IController {
 public:
  /**
   * @brief Constructs a controller
   * @param none
   * @return No return
  **/
  virtual ~IController() {}
  /// Adds an entity to the program
  /**
   * @brief Adds an entity to the program
   * @param entity An entity to be added
   * @return No return
  **/
  virtual void AddEntity(const IEntity& entity) = 0;
  /// Adds an entity to the program
  /**
   * @brief Updates an entity in the program
   * @param entity An entity to be updated
   * @return No return
  **/
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /// Removes an entity from the program
  /**
   * @brief Removes an entity from the program
   * @param id An integer denoting the id of the entity to be removed
   * @return No return
  **/
  virtual void RemoveEntity(int id) = 0;
  /// Adds a path to the program
  /**
   * @brief Adds a path to the program
   * @param id An integer denoting the id of an entity
   * @param path A vector of float vectors that contains a route
   * @return No return
  **/
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /// Removes a path from the program
  /**
   * @brief Removes a path from the program
   * @param id An integer denoting the id of an entity
   * @return No return
  **/
  virtual void RemovePath(int id) = 0;
  /// Allows messages to be passed back to the view
  /**
   * @brief Allows messages to be passed back to the view
   * @param event A string containing the message
   * @param details An object containing details for an entity
   * @return No return
  **/
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;

  /// Stops the controller
  /**
   * @brief Stops the controller
   * @param none
   * @return A boolean denoting a successful stop
  **/
  virtual void stop(void) = 0;

  /// Returns if the controller is alive
  /**
   * @brief Returns if the controller is alive
   * @param none
   * @return A boolean denoting whether the controller is alive
  **/
  virtual bool isAlive(void) = 0;
};

#endif
