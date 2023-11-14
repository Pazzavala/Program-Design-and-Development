#include "RobotFactory.h"
#include "Robot.h"

IEntity* CreateEntity(JsonObject& obj) { return new Robot(obj); }
