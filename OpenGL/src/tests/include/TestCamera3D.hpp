#ifndef TESTCAMERA3D
#define TESTCAMERA3D
#include "IndexBuffer.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include <Test.hpp>
#include <glm/glm.hpp>
#include <Camera.hpp>
class TestCamera3D : public Test {
private:
  glm::mat4 m_Model;
  glm::mat4 m_Projection;
  Camera camera;
  glm::mat4 m_CubeRoationAxis;
  VertexArray *m_vertArray;
  VertexBuffer *m_vertBuffer;
  Shader *m_Shader;
  IndexBuffer *m_indexBuffer;
  Texture* m_Texture;
  float m_RotationAngle;
  glm::vec3 m_Translate;
  char m_texturePath[1024];
public:
  TestCamera3D();
  void Update(float deltaTime) override;
  void Render() override;
  void ImGuiRender() override;
  ~TestCamera3D();
  const char * GetName() override {return "TestCamera3D";}
};
#endif 
