#pragma once
#include "Components.h"
#include <unordered_map>

class ComponentManager {
public:
    std::unordered_map<Entity, TransformComponent> transforms;
    std::unordered_map<Entity, RenderableComponent> renderables;

    void RemoveEntity(Entity e) {
        transforms.erase(e);
        renderables.erase(e);
    }
};
