#ifndef TESTMODEL3D
#define TESTMODEL3D
#include <Test.hpp>
#include <Model.hpp>
#include <glm/glm.hpp>
#include <Camera.hpp>
class TestModel3D : public Test {
private:
  glm::mat4 m_ModelMatrix;
  glm::mat4 m_Projection;
  Camera camera;
  Shader* m_Shader;
  Model* m_Model;
  glm::vec3 m_Translate;
  char m_texturePath[1024];
  float m_CameraSensitivity;
  float m_CameraWalkSpeed;
  float m_Fov;
public:
  TestModel3D();
  void Update(float deltaTime) override;
  void Render() override;
  void ImGuiRender() override;
  ~TestModel3D();
  const char * GetName() override {return "TestModel3D";}
};
#endif 
