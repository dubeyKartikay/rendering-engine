#include <Input.hpp>
#include <stdexcept>
bool Input::GetKeyPressed(char c, const std::string &state){
  unsigned int TRUE_STATE = 0;
  if (state == "pressed")
    TRUE_STATE = GLFW_PRESS;
  else if (state == "released")
    TRUE_STATE = GLFW_RELEASE;
  else
    throw std::logic_error("Invalid state " + state +
                           " state must be 'pressed' or 'released'");
  switch (c) {
  case 'w':
    return glfwGetKey(window, GLFW_KEY_W) == TRUE_STATE;
  case 'a':
    return glfwGetKey(window, GLFW_KEY_A) == TRUE_STATE;
  case 's':
    return glfwGetKey(window, GLFW_KEY_S) == TRUE_STATE;
  case 'd':
    return glfwGetKey(window, GLFW_KEY_D) == TRUE_STATE;
  default:
    throw std::logic_error(
        "Input Polling on specified key not supported yet: " +
        std::string(1, c));
  }
}

const CursorMovementOffset & Input::GetMouseMovementOffset() {
  double xPos,yPos;
  glfwGetCursorPos(window, &xPos, &yPos);
  cursorMovementOffset.first = xPos - cursorMovementOffset.first;
  cursorMovementOffset.second = yPos - cursorMovementOffset.second;
  return cursorMovementOffset ;
}
void Input::SetScrollCallback(const std::function<void(double,double)> & scrollCallback){
    CurrentScrollCallback = scrollCallback;
    glfwSetScrollCallback(window,GLFWScrollCallBackWrapper);
  }
