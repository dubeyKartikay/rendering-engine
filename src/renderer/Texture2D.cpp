#include <GL/gl.h>
#include <Texture2D.hpp>
#include <filesystem>
#include <stb/stb_image.h>
Texture2D::Texture2D(const std::filesystem::path &path)
    : m_RendererId(0), m_LocalBuffer(0), m_Width(0), m_Height(0),
      m_BPP(0),m_Filepath(path) {
  glGenTextures(1, &m_RendererId);
  glBindTexture(GL_TEXTURE_2D, m_RendererId);
  stbi_set_flip_vertically_on_load(1);
  m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, m_LocalBuffer);
  glBindTexture(GL_TEXTURE_2D, 0);
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

std::string Texture2D::GetFilePath() const {
  return this->m_Filepath;
}
