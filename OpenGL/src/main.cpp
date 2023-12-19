#include "Texture.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>
#include <IndexBuffer.hpp>
#include <Shaders.hpp>
#include <VertexArray.hpp>
#include <VertexBuffer.hpp>
#include <Renderer.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
  window = glfwCreateWindow(2560/2, 1440/2, "Hello World", NULL, NULL);
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
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  std::cout << glGetString(GL_VERSION) << std::endl;
  float positions[] = {-0.5f, -0.5f, 0.0f, 0.0f,
                        0.5f, 0.5f, 1.0f, 1.0f,
                        0.5f, -0.5f, 1.0f, 0.0,
                        -0.5f, 0.5f, 0.0f, 1.0f
  };
  unsigned int indices[] = {0, 1, 2, 0, 1, 3};

  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(GLDebugMessageCallback, NULL);

  VertexBuffer *vb = new VertexBuffer(positions, 4*4 * sizeof(float));
  IndexBuffer *id = new IndexBuffer(indices, 6);

  VertexArray *va = new VertexArray();
  VertexBufferLayout *va_layout = new VertexBufferLayout();
  va_layout->Push<float>(2);
  va_layout->Push<float>(2);
  va->AddBuffer(*vb, *va_layout);
  
  glm::mat4 proj = glm::ortho(-1.6f,1.6f,-0.9f,0.9f,-1.0f,1.0f);

  Shader * shader = new Shader(SHADER_DIR "Basic.shader");
  Renderer renderer;
  
  Texture * texture = new Texture(SHADER_DIR "background.png");
  texture->Bind();
  shader->Bind();
  shader->setUniform1i("u_Texture",0);
  shader->setUniformMat4f("u_MVP",proj);
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
//    shader->setUniform4f("u_Color", r, 0.102, 0.344, 1);
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
