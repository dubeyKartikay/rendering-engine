#include <Shaders.hpp>
#include <GLUtils.hpp>
#include <VertexBuffer.hpp>
#include <IndexBuffer.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
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
  float positions[] = {-0.5f, -0.5, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f};
  unsigned int indices[] = {0, 1, 2, 0, 1, 3};
  unsigned int buffer_id;
  unsigned int index_buffer_id;
  unsigned int vertex_array_obj_id;

  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(GLDebugMessageCallback, NULL);



  VertexBuffer * vb = new VertexBuffer(positions,8*sizeof(float));
  IndexBuffer * id = new IndexBuffer(indices,6);


  glGenVertexArrays(1, &vertex_array_obj_id);
  

  // select buffer
  glBindVertexArray(vertex_array_obj_id);
  
  // define buffer layout
  glVertexAttribPointer(VERT_ATTRIB_POSITON, 2, GL_FLOAT, GL_FALSE,
                        2 * sizeof(float), 0);
  
  glEnableVertexAttribArray(VERT_ATTRIB_POSITON);

  ShaderSource s = readShaderFromFile(SHADER_DIR "Basic.shader");
  unsigned int program = CreateShaders(s);
  glUseProgram(program);
  int u_Color_loc = glGetUniformLocation(program, "u_Color");

  float r = 0;
  float inc = 0.05f;
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    if (r >= 1) {
      inc = -inc;
    }
    if (r < 0) {
      inc = -inc;
    }
    glUniform4f(u_Color_loc, r, 0.102, 0.344, 1.0);
    r += inc;
    // draw selected buffer
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(program);
  glfwTerminate();
  return 0;
}
