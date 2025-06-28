// InputManager.h
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager {
public:
    static std::unordered_map<int, bool> keys;
    static double mouseX, mouseY;
    static double deltaX, deltaY;
    static bool firstMouse;

    static void Init(GLFWwindow* window) {
        glfwSetKeyCallback(window, KeyCallback);
        glfwSetCursorPosCallback(window, MouseCallback);
    }

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }

    static void MouseCallback(GLFWwindow* window, double xpos, double ypos) {
        if (firstMouse) {
            mouseX = xpos;
            mouseY = ypos;
            firstMouse = false;
        }

        deltaX = xpos - mouseX;
        deltaY = mouseY - ypos; // inverted Y

        mouseX = xpos;
        mouseY = ypos;
    }

    static bool IsKeyDown(int key) {
        return keys[key];
    }

    static void ResetMouseDelta() {
        deltaX = deltaY = 0.0;
    }
};

#endif
