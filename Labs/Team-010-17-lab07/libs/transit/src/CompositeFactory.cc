#include "CompositeFactory.h"

IEntity* CompositeFactory::CreateEntity(JsonObject& obj) {
    for (int i = 0; i < componentFactories.size(); i++) {
        IEntity* newEntity = componentFactories[i]->CreateEntity(obj);
        if (newEntity != nullptr) {
            return newEntity;
        }
    }
}

void CompositeFactory::AddFactory(IEntityFactory* fact) {
    componentFactories.push_back(fact);
}
