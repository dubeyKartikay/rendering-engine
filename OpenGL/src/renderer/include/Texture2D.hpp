#ifndef TEXTURE
#define TEXTURE
#include <filesystem>
#include <string>
class Texture2D{
  private:
  unsigned int m_RendererId;
  std::filesystem::path m_Filepath;
  unsigned char * m_LocalBuffer;
  int m_Width, m_Height, m_BPP;
  public:
  Texture2D(const std::filesystem::path &path);
  ~Texture2D();
  void Bind(unsigned int slot = 0) const;
  void Unbind() const;

  inline int GetWidth();
  inline int GetHeight();

  void SetActive(unsigned int slot = 0) const;
  std::string GetFilePath() const;
};

#endif // !TEXTURE

