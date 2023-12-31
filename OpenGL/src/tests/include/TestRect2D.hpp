#ifndef TESTRECT2D
#define TESTRECT2D
#include "IndexBuffer.hpp"
#include "Shaders.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include <Test.hpp>

#ifndef SHADER_DIR
#define SHADER_DIR 0
#endif

class TestRect2D: public Test {
private:
  VertexArray * m_vertArray;
  VertexBuffer * m_vertBuffer;
  Shader * m_Shader;
  IndexBuffer * m_indexBuffer;
  float m_rectColor[4];
public:
  TestRect2D();
  void Render() override;
  void ImGuiRender() override;
  ~TestRect2D();
};
#endif 
