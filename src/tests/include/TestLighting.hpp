#ifndef TESTLIGHTING
#define TESTLIGHTING
#include "IndexBuffer.hpp"
#include "Light.hpp"
#include "Texture2D.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include <Test.hpp>
#include <vendor/glm/glm.hpp>
#include <Camera.hpp>
class TestLighting : public Test {
private:
  glm::mat4 m_Model;
  glm::mat4 m_Projection;
  Camera camera;
  glm::mat4 m_CubeRoationAxis;
  VertexArray *m_vertArray;
  VertexBuffer *m_vertBuffer;
  Shader *m_Shader;
  IndexBuffer *m_indexBuffer;
  Texture2D* m_Texture;
  float m_RotationAngle;
  glm::vec3 m_Translate;
  PointLight * m_PointLight;
  char m_texturePath[1024];
  float m_CameraSensitivity;
  float m_CameraWalkSpeed;
  float m_Fov;
public:
  TestLighting();
  void Update(float deltaTime) override;
  void Render() override;
  void ImGuiRender() override;
  ~TestLighting();
  const char * GetName() override {return "TestLighting";}
};
#endif //TESTLIGHTING
