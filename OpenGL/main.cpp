#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main(void) {
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW INIT ERROR" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << glGetString(GL_VERSION) << std::endl;
  float positions[6] = {-0.5f, -0.5, 0.0f, 0.5f, 0.5f, -0.5f};
  unsigned int buffer_id;
  glGenBuffers(1, &buffer_id);
  glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float),positions,GL_STATIC_DRAW);
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3 );
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
