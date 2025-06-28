#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "VAO.h"
#include "shaders.h"
#include "cam.h"

class GameObject {
public:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    VAO vao;
    GLuint texture;
    Shader shader;

    GameObject(VAO vao, GLuint texture, Shader shader)
        : vao(vao), texture(texture), shader(shader),
        position(0.0f), rotation(0.0f), scale(1.0f) {
    }

    void Draw(Camera& camera) {
        shader.Activate();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);
        model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
        model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
        model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
        model = glm::scale(model, scale);

        glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
        camera.Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glUniform1i(glGetUniformLocation(shader.ID, "tex0"), 0);

        vao.Bind();
        glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
    }
};

#endif
