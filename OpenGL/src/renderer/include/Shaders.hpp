#ifndef SHADERS
#define SHADERS
#include "Light.hpp"
#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>
#include <vendor/glm/glm.hpp>
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
  void setUniform1i(const std::string &name,int value);
  void setUniformMat4f(const std::string &name,const glm::mat4& mat);
  void setDirectionalLight(const std::string &name,const DirectionalLight & directionalLight,bool isArray = false,int index = 0);
  void setPointLight(const PointLight & pointLight,bool isArray = false ,int index = 0);
  void setMultipleDirectionalLight(const std::string & name,std::vector<DirectionalLight> & directionalLights);
  void setMultiplePointLight(const std::string & name, std::vector<PointLight> & pointLights);
};

#endif // !SHADERS
