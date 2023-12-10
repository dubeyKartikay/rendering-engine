#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>
#include <IndexBuffer.hpp>
#include <Shaders.hpp>
#include <VertexArray.hpp>
#include <VertexBuffer.hpp>
#include <Renderer.hpp>
#define VERT_ATTRIB_POSITON 0
#define VERT_ATTRIB_POSITON_NCOMP 2
#ifndef SHADER_DIR
#define SHADER_DIR 0
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
  
  Shader * shader = new Shader(SHADER_DIR "Basic.shader");
  Renderer renderer;
  float r = 0;
  float inc = 0.05f;
  vb->Unbind();
  id->Unbind();
  va->Unbind();
  shader->Unbind();
  while (!glfwWindowShouldClose(window)) {
    renderer.Clear();
    if (r >= 1) {
      inc = -inc;
    }
    if (r < 0) {
      inc = -inc;
    }
    r += inc;
    shader->Bind();
    shader->setUniform4f("u_Color", r, 0.102, 0.344, 1);
    renderer.Draw(*va, *id, *shader);  
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  delete va;
  delete vb;
  delete id;
  delete shader;
  return 0;
}
