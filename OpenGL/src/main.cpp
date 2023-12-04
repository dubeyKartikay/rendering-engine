#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <algorithm>
#include <asm-generic/errno-base.h>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

#define VERT_ATTRIB_POSITON 0
#define VERT_ATTRIB_POSITON_NCOMP 2
#define SHADER_ERROR_MESG_BUFF_SIZE 2048

void APIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
                                     GLenum severity, GLsizei length,
                                     const GLchar *msg, const void *data) {
  std::string _source;
  std::string _type;
  std::string _severity;

  switch (source) {
  case GL_DEBUG_SOURCE_API:
    _source = "API";
    break;

  case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
    _source = "WINDOW SYSTEM";
    break;

  case GL_DEBUG_SOURCE_SHADER_COMPILER:
    _source = "SHADER COMPILER";
    break;

  case GL_DEBUG_SOURCE_THIRD_PARTY:
    _source = "THIRD PARTY";
    break;

  case GL_DEBUG_SOURCE_APPLICATION:
    _source = "APPLICATION";
    break;

  case GL_DEBUG_SOURCE_OTHER:
    _source = "UNKNOWN";
    break;

  default:
    _source = "UNKNOWN";
    break;
  }

  switch (type) {
  case GL_DEBUG_TYPE_ERROR:
    _type = "ERROR";
    break;

  case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
    _type = "DEPRECATED BEHAVIOR";
    break;

  case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
    _type = "UDEFINED BEHAVIOR";
    break;

  case GL_DEBUG_TYPE_PORTABILITY:
    _type = "PORTABILITY";
    break;

  case GL_DEBUG_TYPE_PERFORMANCE:
    _type = "PERFORMANCE";
    break;

  case GL_DEBUG_TYPE_OTHER:
    _type = "OTHER";
    break;

  case GL_DEBUG_TYPE_MARKER:
    _type = "MARKER";
    break;

  default:
    _type = "UNKNOWN";
    break;
  }

  switch (severity) {
  case GL_DEBUG_SEVERITY_HIGH:
    _severity = "HIGH";
    break;

  case GL_DEBUG_SEVERITY_MEDIUM:
    _severity = "MEDIUM";
    break;

  case GL_DEBUG_SEVERITY_LOW:
    _severity = "LOW";
    break;

  case GL_DEBUG_SEVERITY_NOTIFICATION:
    _severity = "NOTIFICATION";
    break;

  default:
    _severity = "UNKNOWN";
    break;
  }
  std::cout << id << ": " << _type << " of " << _severity
            << " severity, raised from " << _source << ": " << msg << std::endl;
}

struct ShaderSource {
  std::string vertex_shader;
  std::string fragment_shader;
};

ShaderSource readShaderFromFile(std::filesystem::path path) {
  enum ShaderType {
    NONE = -1,
    VERTEX_SHADER,
    FRAGMENT_SHADER
  } currentOpenShader;
  std::ifstream file(path);
  std::stringstream shader_sources[2];
  if (!file.is_open()) {
    std::cout << "Cannot open File" << std::endl;
    exit(EXIT_FAILURE);
  }
  while (!file.eof()) {
    std::string buf;
    std::getline(file, buf);
    if (buf.find("#shader") != std::string::npos) {
      if (buf.find("vertex") != std::string::npos)
        currentOpenShader = ShaderType::VERTEX_SHADER;
      else
        currentOpenShader = ShaderType::FRAGMENT_SHADER;
      continue;
    }
    shader_sources[currentOpenShader] << buf << '\n';
  }
  return {shader_sources[ShaderType::VERTEX_SHADER].str(),
          shader_sources[ShaderType::FRAGMENT_SHADER].str()};
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

static unsigned int CreateShaders(ShaderSource &shader_source) {
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
  // generate buffers
  glGenBuffers(1, &buffer_id);
  glGenBuffers(1, &index_buffer_id);
  glGenVertexArrays(1, &vertex_array_obj_id);
  // select buffer
  glBindVertexArray(vertex_array_obj_id);
  glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
  // fill buffer
  glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), positions, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(float), indices,
               GL_STATIC_DRAW);
  // define buffer layout
  glVertexAttribPointer(VERT_ATTRIB_POSITON, 2, GL_FLOAT, GL_FALSE,
                        2 * sizeof(float), 0);
  glEnableVertexAttribArray(VERT_ATTRIB_POSITON);

  ShaderSource s = readShaderFromFile("./res/Basic.shader");
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
