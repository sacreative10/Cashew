
#include "Input.h"

#include <CashewLib/Application.h>

#include <GLFW/glfw3.h>

namespace Cashew {
bool Input::isKeyPressed(KeyCode keycode) {
  GLFWwindow *windowHandle = Application::Get().GetWindowHandle();
  int state = glfwGetKey(windowHandle, (int)keycode);
  return state == GLFW_PRESS;
}

bool Input::isKeyDown(KeyCode keycode) {
  GLFWwindow *windowHandle = Application::Get().GetWindowHandle();
  int state = glfwGetKey(windowHandle, (int)keycode);
  return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::isMouseButtonDown(MouseButton button) {
  GLFWwindow *windowHandle = Application::Get().GetWindowHandle();
  int state = glfwGetMouseButton(windowHandle, (int)button);
  return state == GLFW_PRESS;
}

glm::vec2 Input::getMousePosition() {
  GLFWwindow *windowHandle = Application::Get().GetWindowHandle();

  double x, y;
  glfwGetCursorPos(windowHandle, &x, &y);
  return {(float)x, (float)y};
}

void Input::setCursorMode(CursorMode mode) {
  GLFWwindow *windowHandle = Application::Get().GetWindowHandle();
  glfwSetInputMode(windowHandle, GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)mode);
}
} // namespace Cashew