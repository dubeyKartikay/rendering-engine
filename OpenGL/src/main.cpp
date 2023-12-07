#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>
#include <IndexBuffer.hpp>
#include <Shaders.hpp>
#include <VertexArray.hpp>
#include <VertexBuffer.hpp>
#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>

#define VERT_ATTRIB_POSITON 0
#define VERT_ATTRIB_POSITON_NCOMP 2
#ifndef SHADER_DIR
#define SHADER_DIR
#endif

int main(void) {
  GLFWwindow *window;
  std::cout << "Started program" << std::endl;
  /* Initialize the library */
  if (!glfwInit())
    return -1;

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    std::cout << "Unable to create a window" << std::endl;
    const char *description;
    int code = glfwGetError(&description);
    std::cout << description << std::endl;
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);
  glfwSwapInterval(2);
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW INIT ERROR" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::cout << glGetString(GL_VERSION) << std::endl;
  float positions[] = {-0.5f, -0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f};
  unsigned int indices[] = {0, 1, 2, 0, 1, 3};

  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(GLDebugMessageCallback, NULL);

  VertexBuffer *vb = new VertexBuffer(positions, 8 * sizeof(float));
  IndexBuffer *id = new IndexBuffer(indices, 6);

  VertexArray *va = new VertexArray();
  VertexBufferLayout *va_layout = new VertexBufferLayout();
  va_layout->Push<float>(2);
  va->AddBuffer(*vb, *va_layout);
  
  ShaderSource s = readShaderFromFile(SHADER_DIR "Basic.shader");
  unsigned int program = CreateShaders(s);
  glUseProgram(program);
  int u_Color_loc = glGetUniformLocation(program, "u_Color");

  float r = 0;
  float inc = 0.05f;
  glBindBuffer(GL_ARRAY_BUFFER,0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
  glBindVertexArray(0);
  glUseProgram(0);
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    if (r >= 1) {
      inc = -inc;
    }
    if (r < 0) {
      inc = -inc;
    }
    r += inc;
    glUseProgram(program);
    glUniform4f(u_Color_loc, r, 0.102, 0.344, 1.0);
    // draw selected buffer
    va->Bind();
    id->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(program);
  glfwTerminate();
  return 0;
}
