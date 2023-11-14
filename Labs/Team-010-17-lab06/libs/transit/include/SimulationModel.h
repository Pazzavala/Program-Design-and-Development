#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "Drone.h"
#include "IController.h"
#include "IEntity.h"
#include "Package.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/**
 * @brief Simulation Model handling the transit simulation.  The model can communicate with the controller.
 * 
*/
class SimulationModel {
 public:
  /**
   * @brief Constructor to create a SimulationModel object.
   * 
   * @param controller that controlls an entity.
  */
  SimulationModel(IController& controller);

  /**
   * @brief Sets the graph attribute to the passed in graph.
   * 
   * @param graph a graph that contains nodes.
  */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Creates an simulation entity.
   * 
   * @param entity an object that represents the entity to be created.
  */
  void CreateEntity(JsonObject& entity);

  /**
   * @brief Schedules a trip for an object in the scene.
   * 
   * @param details details of the trips schedule.
  */
  void ScheduleTrip(JsonObject& details);

  /**
   * @brief Updates the simulation.
   * 
   * @param dt a number representing the time change.
  */
  void Update(double dt);

  /**
   * @brief Stops the simulation.
  */
  void stop(void);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
};

#endif
