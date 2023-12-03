#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

#define VERT_ATTRIB_POSITON 0
#define VERT_ATTRIB_POSITON_NCOMP 2
#define SHADER_ERROR_MESG_BUFF_SIZE 2048
static unsigned int CompileShader(unsigned int type,
                                  const std::string &shader) {
  unsigned int shader_id = glCreateShader(type);
  const char *shader_src = shader.c_str();
  glShaderSource(shader_id, 1, &shader_src, NULL);
  glCompileShader(shader_id);
  int shader_compile_status = 0;
  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shader_compile_status);
  if (shader_compile_status == GL_FALSE) {
    int len = 0;
    char emsg[SHADER_ERROR_MESG_BUFF_SIZE];
    glGetShaderInfoLog(shader_id, SHADER_ERROR_MESG_BUFF_SIZE, &len, emsg);
    std::cout << emsg << std::endl;
    glDeleteShader(shader_id);
    return 0;
  }
  return shader_id;
}

static unsigned int CreateShaders(const std::string &vertex_shader,
                                  const std::string &fragment_shader) {
  unsigned int program = glCreateProgram();
  unsigned int vertex_shader_id =
      CompileShader(GL_VERTEX_SHADER, vertex_shader);
  unsigned int fragment_shader_id =
      CompileShader(GL_FRAGMENT_SHADER, fragment_shader);
  glAttachShader(program, vertex_shader_id);
  glAttachShader(program, fragment_shader_id);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vertex_shader_id);
  glDeleteShader(fragment_shader_id);

  return program;
}
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

  // generate buffer
  glGenBuffers(1, &buffer_id);

  // select buffer
  glBindBuffer(GL_ARRAY_BUFFER, buffer_id);

  // fill buffer
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  // define buffer layout
  glVertexAttribPointer(VERT_ATTRIB_POSITON, 2, GL_FLOAT, GL_FALSE,
                        2 * sizeof(float), 0);
  glEnableVertexAttribArray(VERT_ATTRIB_POSITON);
  const std::string vs = R"glsl(
  #version 330 core

  layout(location = 0) in vec4 position;

  void main(){
     gl_Position = position;
  }
  )glsl";

 const std::string fs = R"glsl(
  #version 330 core

  layout(location = 0) out vec4 color;

  void main(){
     color = vec4(0.102,0.1059,0.142,1);
  }
  )glsl";

  unsigned int program = CreateShaders(vs, fs);
  glUseProgram(program);

  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    // draw selected buffer
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
