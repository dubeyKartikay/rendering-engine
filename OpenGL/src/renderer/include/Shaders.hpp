#ifndef SHADERS
#define SHADERS
#include <GL/glew.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#ifndef SHADER_ERROR_MESG_BUFF_SIZE
#define SHADER_ERROR_MESG_BUFF_SIZE 2048
#endif

struct ShaderSource {
  std::string vertex_shader;
  std::string fragment_shader;
};

class Shader {
private:
  ShaderSource m_ShaderSource;
  unsigned int m_RendererID;
  std::unordered_map<std::string,int> uniform_loc_cache;

  unsigned int CreateShaders(ShaderSource &shader_source);
  unsigned int CompileShader(unsigned int type, const std::string &shader);
  ShaderSource readShaderFromFile(std::filesystem::path path);
  int GetUniformLocation(const std::string &name);

public:
  Shader(const std::filesystem::path &path);
  ~Shader();
  void Bind() const;
  void Unbind() const;
  void setUniform4f(const std::string &name, float v0,float v1,float v2, float v3);
};

#endif // !SHADERS
