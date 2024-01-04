#ifndef INPUT
#define INPUT
#include <GLFW/glfw3.h>
#include <functional>
#include <string>
struct CursorMovementOffset {
  double x, y;
};
class Input {
private:
  Input() = delete;
  static GLFWwindow *window;
  static CursorMovementOffset cursorMovementOffset;
  static std::function<void(double,double)> CurrentScrollCallback;
  static void GLFWScrollCallBackWrapper(GLFWwindow * window  , double xPos, double ypos){ CurrentScrollCallback(xPos,ypos); }
public:
  Input(const Input &obj) = delete;
  Input &operator=(const Input &) = delete;
  static void Initialize(GLFWwindow *window) { window = window; }
  static bool GetKeyPressed(char c, const std::string &state = "pressed");
  static const CursorMovementOffset &GetMouseMovementOffset() ;
  static void SetScrollCallback(const std::function<void(double,double)> & scrollCallback);
};
#endif // DEBUG
