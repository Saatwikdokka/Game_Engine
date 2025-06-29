#pragma once

#include "ComponentManager.h"
#include "cam.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class RenderSystem {
public:
    void Update(const ComponentManager& cm, const Camera& camera) {
        for (auto it = cm.renderables.begin(); it != cm.renderables.end(); ++it) {
            Entity entity = it->first;
            const RenderableComponent& renderable = it->second;

            if (cm.transforms.find(entity) == cm.transforms.end())
                continue;

            const TransformComponent& transform = cm.transforms.at(entity);

            renderable.shader->Activate();   // Activate shader if needed

            glBindVertexArray(renderable.VAO);
            glBindTexture(GL_TEXTURE_2D, renderable.textureID);

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, transform.position);
            model = glm::rotate(model, glm::radians(transform.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::scale(model, transform.scale);

            GLuint modelLoc = glGetUniformLocation(renderable.shader->ID, "model"); 


            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            // Camera Matrix uniform update
            camera.Matrix(45.0f, 0.1f, 100.0f, *(renderable.shader), "camMatrix");


            glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
        }
    }
};
