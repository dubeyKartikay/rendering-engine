#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <algorithm>
#include <asm-generic/errno-base.h>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <fstream>

#define VERT_ATTRIB_POSITON 0
#define VERT_ATTRIB_POSITON_NCOMP 2
#define SHADER_ERROR_MESG_BUFF_SIZE 2048

struct ShaderSource{
  std::string vertex_shader;
  std::string fragment_shader;
};

ShaderSource readShaderFromFile(std::filesystem::path path){
  enum ShaderType {
    NONE = -1, VERTEX_SHADER,FRAGMENT_SHADER
  } currentOpenShader;
  std::ifstream file (path);
  std::stringstream shader_sources[2];
  if(!file.is_open()) {
    std::cout << "Cannot open File" << std::endl;
    exit(EXIT_FAILURE);
  }
  while (!file.eof()) {
    std::string buf;
    std::getline(file,buf);
    if(buf.find("#shader") != std::string::npos) {
      if(buf.find("vertex") != std::string::npos) currentOpenShader = ShaderType::VERTEX_SHADER;
      else currentOpenShader = ShaderType::FRAGMENT_SHADER;
      continue;
    }
    shader_sources[currentOpenShader] << buf << '\n';
    
  }
  return {shader_sources[ShaderType::VERTEX_SHADER].str(),shader_sources[ShaderType::FRAGMENT_SHADER].str()};
}
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

static unsigned int CreateShaders(ShaderSource& shader_source) {
  unsigned int program = glCreateProgram();
  unsigned int vertex_shader_id =
      CompileShader(GL_VERTEX_SHADER, shader_source.vertex_shader);
  unsigned int fragment_shader_id =
      CompileShader(GL_FRAGMENT_SHADER, shader_source.fragment_shader);
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
  ShaderSource s = readShaderFromFile("./res/Basic.shader"); 
  unsigned int program = CreateShaders(s);
  glUseProgram(program);

  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    // draw selected buffer
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(program);
  glfwTerminate();
  return 0;
}
