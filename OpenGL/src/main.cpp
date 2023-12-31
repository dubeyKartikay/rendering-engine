#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>
#include <IndexBuffer.hpp>
#include <Renderer.hpp>
#include <Shaders.hpp>
#include <Texture.hpp>
#include <VertexArray.hpp>
#include <VertexBuffer.hpp>
#include <TestCamera3D.hpp>
#include <TestCube3D.hpp>
#include <TestFrame.hpp>
#include <TestRect2D.hpp>
#include <TestTexture2D.hpp>
#include <TestTexture3D.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vendor/imgui/imgui.h>
#include <vendor/imgui/imgui_impl_glfw.h>
#include <vendor/imgui/imgui_impl_opengl3.h>
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
  window = glfwCreateWindow(2560 / 2, 1440 / 2, "Hello World", NULL, NULL);
  if (!window) {
    std::cout << "Unable to create a window" << std::endl;
    const char *description;
    int code = glfwGetError(&description);
    std::cout << description << std::endl;
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(2);
  if (glewInit() != GLEW_OK) {
    std::cout << "GLEW INIT ERROR" << std::endl;
    exit(EXIT_FAILURE);
  }

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init();

  glEnable(GL_BLEND);
  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(GLDebugMessageCallback, NULL);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  std::cout << glGetString(GL_VERSION) << std::endl;
  TestFrame tests;
  tests.AddTest(new TestRect2D());
  tests.AddTest(new TestCube3D());
  tests.AddTest(new TestTexture2D());
  while (!glfwWindowShouldClose(window)) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    tests.Clear();
    tests.Render();
    tests.ImGuiRender();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  TestFrame tf;
  tf.AddTest(new TestFrame());
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwTerminate();
  return 0;
}
