#include <Shaders.hpp>

Shader::Shader(const std::filesystem::path &path){
  m_ShaderSource = readShaderFromFile(path);
  m_RendererID =  CreateShaders(m_ShaderSource);
}
Shader::~Shader(){
  glDeleteProgram(m_RendererID);
}
void Shader::Bind() const{
  glUseProgram(m_RendererID);
}
void Shader::Unbind() const{
  glUseProgram(0);
}
void Shader::setUniform4f(const std::string &name, float v0,float v1,float v2, float v3){
  glUniform4f(GetUniformLocation(name),v0,v1,v2,v3); 
}

ShaderSource Shader::readShaderFromFile(std::filesystem::path path) {
  if (SHADER_DIR == 0) {
    std::cout << "Shaders not defined" << std::endl;
    exit(EXIT_FAILURE);
  }
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


unsigned int Shader::CompileShader(unsigned int type, const std::string &shader) {
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
