#include "Light.hpp"
#include <GL/glew.h>
#include <Shaders.hpp>
#include <algorithm>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
Shader::Shader(const std::filesystem::path &path) {
  m_ShaderSource = readShaderFromFile(path);
  m_RendererID = CreateShaders(m_ShaderSource);
}
Shader::~Shader() {
  std::cout << "Shader Destroyed" << std::endl;
  glDeleteProgram(m_RendererID);
}
void Shader::Bind() const { glUseProgram(m_RendererID); }
void Shader::Unbind() const { glUseProgram(0); }
void Shader::setUniform4f(const std::string &name, float v0, float v1, float v2,
                          float v3) {
  glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::setUniformVec3(const std::string &name, const glm::vec3 &vector) {
  glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
}

void Shader::setUniformVec4(const std::string &name, const glm::vec4 &vector) {
  glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}

void Shader::setUniform1i(const std::string &name, int value) {
  glUniform1i(GetUniformLocation(name), value);
}
void Shader::setUniformMat4f(const std::string &name, const glm::mat4 &mat) {
  glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE,
                     glm::value_ptr(mat));
}

void Shader::setUniformDirectionalLight(
    const std::string &name, const DirectionalLight &directionalLight,
    bool isArray, int index) {
  std::string uniformName = name;
  if (isArray) {
    uniformName = name + "[" + std::to_string(index) + "]";
  }
  setUniformVec3(uniformName + ".direction", directionalLight.direction);
  setUniformVec3(uniformName + ".ambient", directionalLight.ambient);
  setUniformVec3(uniformName + ".diffuse", directionalLight.diffuse);
  setUniformVec3(uniformName + ".specular", directionalLight.specular);
}

void Shader::setUniformMultipleDirectionalLight(
    const std::string &name, std::vector<DirectionalLight> &directionalLights) {
  for (int i = 0; i < directionalLights.size(); i++) {
    setUniformDirectionalLight(name, directionalLights[i], true, i);
  }
}

void Shader::setUniformPointLight(const std::string &name,
                                  const PointLight &pointLight, bool isArray,
                                  int index) {

  std::string uniformName = name;
  if (isArray) {
    uniformName = name + "[" + std::to_string(index) + "]";
  }
  setUniformVec3(uniformName + ".position", pointLight.position);
  setUniformVec3(uniformName + ".ambient", pointLight.ambient);
  setUniformVec3(uniformName + ".diffuse", pointLight.diffuse);
  setUniformVec3(uniformName + ".specular", pointLight.specular);
  glUniform1f(GetUniformLocation(uniformName + ".constant"),pointLight.constant);
  glUniform1f(GetUniformLocation(uniformName + ".linear"),pointLight.linear);
  glUniform1f(GetUniformLocation(uniformName + ".quadratic"),pointLight.quadratic);
}


void Shader::setUniformMaterial(const std::string & name ,const Material & material){
  glUniform1i(GetUniformLocation(name + ".diffuse"),material.diffuse);
  glUniform1i(GetUniformLocation(name + ".specular"),material.specular);
  glUniform1f(GetUniformLocation(name + ".shininess"),material.shininess);
}

void Shader::setUniformMultiplePointLight(const std::string & name, std::vector<PointLight> & pointLights){
  for (size_t i = 0; i < pointLights.size(); i++) {
    setUniformPointLight(name, pointLights[i],true,i);
  }
}
int Shader::GetUniformLocation(const std::string &name) {
  if (auto cache_search = uniform_loc_cache.find(name);
      cache_search != uniform_loc_cache.end()) {
    return cache_search->second;
  }
  int location = glGetUniformLocation(m_RendererID, name.c_str());
  if(location < 0){
    std::cout << "Uniform not found" << std::endl;
  }else{
    uniform_loc_cache[name] = location;
  }
  return location;
}

ShaderSource Shader::readShaderFromFile(std::filesystem::path path) {
  if (SHADER_DIR == 0) {
    std::cout << "Shaders not defined" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::cout << "Reading Shader file: " << path << std::endl;
  enum ShaderType {
    NONE = -1,
    VERTEX_SHADER,
    FRAGMENT_SHADER
  } currentOpenShader;
  std::ifstream file(path);
  std::stringstream shader_sources[2];
  if (!file.is_open()) {

    std::cout << "Cannot open File: " << SHADER_DIR << std::endl;
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

unsigned int Shader::CompileShader(unsigned int type,
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

unsigned int Shader::CreateShaders(ShaderSource &shader_source) {
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
