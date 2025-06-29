
#include <glm/glm.hpp>
#include <glad/glad.h>

struct TransformComponent {
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};
struct RenderableComponent {
    GLuint VAO;
    Shader* shader;       // Pointer to Shader class
    GLuint textureID;
};

