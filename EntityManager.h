#pragma once
#include <queue>
#include <cstdint>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;

class EntityManager {
private:
    std::queue<Entity> availableEntities;

public:
    EntityManager() {
        for (Entity e = 0; e < MAX_ENTITIES; ++e)
            availableEntities.push(e);
    }

    Entity CreateEntity() {
        Entity id = availableEntities.front();
        availableEntities.pop();
        return id;
    }

    void DestroyEntity(Entity entity) {
        // You can also remove from all components here if needed
        availableEntities.push(entity);
    }
};
