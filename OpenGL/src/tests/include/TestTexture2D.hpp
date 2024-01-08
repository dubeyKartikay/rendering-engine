#ifndef TESTTEXTURE2D
#define TESTTEXTURE2D
#include "IndexBuffer.hpp"
#include "Shaders.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include <Test.hpp>
class TestTexture2D : public Test {
private:
  VertexArray *m_vertArray;
  VertexBuffer *m_vertBuffer;
  Shader *m_Shader;
  IndexBuffer *m_indexBuffer;
  Texture2D* m_Texture;
  char m_texturePath[1024];
public:
  TestTexture2D();
  void Render() override;
  void ImGuiRender() override;
  const char * GetName() override {return "TestTexture2D";}
  ~TestTexture2D();
};
#endif
