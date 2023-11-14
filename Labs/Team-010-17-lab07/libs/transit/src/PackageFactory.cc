#include "PackageFactory.h"
#include "Package.h"

IEntity* CreateEntity(JsonObject& obj) { return new Package(obj); }
