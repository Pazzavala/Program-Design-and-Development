#include "DroneFactory.h"
#include "Drone.h"

IEntity* CreateEntity(JsonObject& obj) { return new Drone(obj); }
