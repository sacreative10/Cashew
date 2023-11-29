#ifndef CASHEW_INPUT_H

#include "KeyCodes.h"

#include <glm/glm.hpp>

namespace Cashew {
class Input {
public:
  static bool isKeyDown(KeyCode keyCode);
  static bool isKeyPressed(KeyCode keyCode);
  static bool isMouseButtonDown(MouseButton button);

  static glm::vec2 getMousePosition();

  static void setCursorMode(CursorMode mode);
};
}; // namespace Cashew

#endif // !INPUT_
