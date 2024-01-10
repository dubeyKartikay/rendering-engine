#include <GL/glew.h>
#include <Texture2D.hpp>
#include <filesystem>
#include <iostream>
#include <stb/stb_image.h>
#include <stdexcept>
Texture2D::Texture2D(const std::filesystem::path &path)
    : m_RendererId(0), m_LocalBuffer(0), m_Width(0), m_Height(0), m_BPP(0),
      m_Filepath(path) {
  std::cout<< "Loading texture at " << path << std::endl;
  glGenTextures(1, &m_RendererId);
  glBindTexture(GL_TEXTURE_2D, m_RendererId);
  m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 0);
  if(!m_LocalBuffer){
      throw std::runtime_error("Unable to load texture");
  }
  GLenum format;
  if (m_BPP == 1)
    format = GL_RED;
  else if (m_BPP == 3)
    format = GL_RGB;
  else if (m_BPP == 4)
    format = GL_RGBA;
  stbi_set_flip_vertically_on_load(0);
  glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format,
               GL_UNSIGNED_BYTE, m_LocalBuffer);
  glGenerateMipmap(GL_TEXTURE_2D);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  if (m_LocalBuffer)
    stbi_image_free(m_LocalBuffer);
}
Texture2D::~Texture2D() { glDeleteTextures(1, &m_RendererId); }
void Texture2D::Bind(unsigned int slot) const {
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, m_RendererId);
}
void Texture2D::SetActive(unsigned int slot) const {
  glActiveTexture(GL_TEXTURE0 + slot);
}
void Texture2D::Unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

std::string Texture2D::GetFilePath() const { return this->m_Filepath; }
