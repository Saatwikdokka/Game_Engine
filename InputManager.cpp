#include "InputManager.h"
#include <GLFW/glfw3.h>

InputManager::InputManager(GLFWwindow* window)
    : window(window)
{
    // Initialize previous state arrays
    keys.fill(false);
    mouseButtons.fill(false);
}

void InputManager::Update()
{
    // Store previous key and mouse states
    prevKeys = keys;
    prevMouseButtons = mouseButtons;

    // Update key states
    for (int key = 0; key < GLFW_KEY_LAST; ++key)
        keys[key] = glfwGetKey(window, key) == GLFW_PRESS;

    // Update mouse button states
    for (int button = 0; button < GLFW_MOUSE_BUTTON_LAST; ++button)
        mouseButtons[button] = glfwGetMouseButton(window, button) == GLFW_PRESS;

    // Update mouse position
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    mouseX = static_cast<float>(x);
    mouseY = static_cast<float>(y);
}

bool InputManager::IsKeyPressed(int key) const
{
    return keys[key] && !prevKeys[key];
}

bool InputManager::IsKeyReleased(int key) const
{
    return !keys[key] && prevKeys[key];
}

bool InputManager::IsKeyDown(int key) const
{
    return keys[key];
}

bool InputManager::IsMousePressed(int button) const
{
    return mouseButtons[button] && !prevMouseButtons[button];
}

bool InputManager::IsMouseReleased(int button) const
{
    return !mouseButtons[button] && prevMouseButtons[button];
}

bool InputManager::IsMouseDown(int button) const
{
    return mouseButtons[button];
}

float InputManager::GetMouseX() const
{
    return mouseX;
}

float InputManager::GetMouseY() const
{
    return mouseY;
}
