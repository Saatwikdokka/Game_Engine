#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "GameObject.h"

class Scene {
public:
    std::vector<GameObject> objects;

    void Add(const GameObject& obj) {
        objects.push_back(obj);
    }

    void Draw(Camera& camera) {
        for (auto& obj : objects) {
            obj.Draw(camera);
        }
    }
};

#endif