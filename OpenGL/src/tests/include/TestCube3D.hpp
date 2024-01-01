#ifndef TESTCUBE3D
#define TESTCUBE3D
#include "IndexBuffer.hpp"
#include "Shaders.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include <Test.hpp>
#include <glm/fwd.hpp>
class TestCube3D : public Test {
private:
  VertexArray *m_vertArray;
  VertexBuffer *m_vertBuffer;
  Shader *m_Shader;
  IndexBuffer *m_indexBuffer;
  Texture* m_Texture;
  glm::mat4 m_View;
  glm::mat4 m_Projection;
  glm::mat4 m_Model;
  glm::vec3 m_RotationAxis;
  float m_RotationAngle;
  glm::vec3 m_Translate;
  char m_texturePath[1024];

public:
  void Update() override;
  TestCube3D();
  void Render() override;
  void ImGuiRender() override;
  ~TestCube3D();
};
#endif 
