#ifndef SHADERS
#define SHADERS
#include <GL/glew.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#ifndef SHADER_ERROR_MESG_BUFF_SIZE
#define SHADER_ERROR_MESG_BUFF_SIZE 2048
#endif

struct ShaderSource {
  std::string vertex_shader;
  std::string fragment_shader;
};
ShaderSource readShaderFromFile(std::filesystem::path path);
unsigned int CompileShader(unsigned int type, const std::string &shader);
unsigned int CreateShaders(ShaderSource &shader_source);
#endif // !SHADERS
