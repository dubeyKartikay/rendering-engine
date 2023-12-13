#ifndef TEXTURE
#define TEXTURE
#include <filesystem>
class Texture{
  private:
  unsigned int m_RendererId;
  std::filesystem::path m_Filepath;
  unsigned char * m_LocalBuffer;
  int m_Width, m_Height, m_BPP;
  public:
  Texture(const std::filesystem::path &path);
  ~Texture();
  void Bind(unsigned int slot = 0) const;
  void Unbind() const;

  inline int GetWidth();
  inline int GetHeight();
};

#endif // !TEXTURE

