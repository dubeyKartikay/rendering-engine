#include "Input.hpp"
#include "glm/fwd.hpp"
#include "vendor/imgui/imgui.h"
#include <Light.hpp>
#include <Renderer.hpp>
#include <TestLighting.hpp>
#include <cstring>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
TestLighting::TestLighting()
    : m_Model(1.0f), m_Projection(1.0f), m_Translate(0.0f, 0.0f, -3.0f),
      m_CubeRoationAxis(1.0f), m_RotationAngle(0.0f), m_CameraSensitivity(1.0f),
      m_CameraWalkSpeed(1.0f), m_Fov(45.0f) {
  m_Shader = new Shader(SHADER_DIR "DefaultLight3D.shader");
  float positions[] = {
      // positions        //normals       // texture coords
      0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.5f, 1.0f, 1.0f, // top right
      0.5f,  -0.5f, 0.5f,  1.0f, 0.0f,                   // bottom right
      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f,                   // bottom left
      -0.5f, 0.5f,  0.5f,  0.0f, 0.0f, 0.5f, 0.0f, 1.0f,                   // top left

      0.5f,  0.5f,  -0.5f, 0.0f, 0.0f, -0.5f, 0.0f, 1.0f, // top right
      0.5f,  -0.5f, -0.5f, 0.0f, 0.0f, // bottom right
      -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -0.5f, 1.0f, 0.0f, // bottom left
      -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f  // top left
  };
  unsigned int index[] = {0, 1, 2,
                          2, 3, 0,
                          4, 5, 6,
                          7, 6, 4,
                          1, 4, 0,
                          5, 4, 1,
                          6, 5, 1,
                          6, 2, 1,
                          0, 4, 7,
                          0, 3, 7,
                          7, 3, 6,
                          3, 6, 2};

  PointLight pointLight(
      glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f),
      glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

  m_vertBuffer = new VertexBuffer(positions, sizeof(positions));
  m_vertArray = new VertexArray();
  m_indexBuffer = new IndexBuffer(index, 6 * 3 * 2);
  VertexBufferLayout layout;
  layout.Push<float>(3);
  layout.Push<float>(3);
  layout.Push<float>(2);
  m_vertArray->AddBuffer(*m_vertBuffer, layout);
  strcpy(m_texturePath, SHADER_DIR "background.png");
  m_Texture = new Texture2D(m_texturePath);
  Renderer::GetRenderer()->EnableDepthTesting();
  m_Projection =
      glm::perspective(glm::radians(m_Fov), 800.0f / 600.0f, 0.1f, 100.0f);
  m_Model = glm::translate(m_Model, m_Translate);
  m_Shader->Bind();
  Material material(0, 0, 32);
  m_Shader->setUniformMaterial("u_Material", material);
  m_Shader->setUniformMat4f("u_Projection", m_Projection);
  m_Shader->setUniformMat4f("u_Model", m_Model);
  m_Shader->setUniformPointLight("u_PointLights", pointLight, true);
  m_Shader->Unbind();
  Input::SetScrollCallback([this](double xOff, double yOff) {
    m_Fov -= yOff;
    if (m_Fov < 1.0f)
      m_Fov = 1.0f;
    if (m_Fov > 45.0f)
      m_Fov = 45.0f;
    m_Projection =
        glm::perspective(glm::radians(m_Fov), 800.0f / 600.0f, 0.1f, 100.0f);
  });
}

void TestLighting::Update(float deltaTime) {
  m_Model = glm::rotate(m_Model, glm::radians(50.0f) * 2 * deltaTime,
                        glm::vec3(0.5f, 1.0f, 0.0f));
  if (Input::GetKeyPressed('w')) {
    camera.Translate({0, 0, -1.0f * deltaTime * m_CameraWalkSpeed});
  } else if (Input::GetKeyPressed('s')) {
    camera.Translate({0, 0, 1.0f * deltaTime * m_CameraWalkSpeed});
  } else if (Input::GetKeyPressed('a')) {
    camera.Translate({-1.0 * deltaTime * m_CameraWalkSpeed, 0, 0});
  } else if (Input::GetKeyPressed('d')) {
    camera.Translate({1.0f * deltaTime * m_CameraWalkSpeed, 0, 0});
  }
  CursorMovementOffset mouseMovement = Input::GetMouseMovementOffset();
  camera.IncrementYaw(-1 * mouseMovement.first * deltaTime *
                      m_CameraSensitivity);
  camera.IncrementPitch(-1 * mouseMovement.second * deltaTime *
                        m_CameraSensitivity);
  glm::vec3 lookDir;
  lookDir.x = glm::cos(glm::radians(camera.GetYaw())) *
              glm::cos(glm::radians(camera.GetPitch()));
  lookDir.y = glm::sin(glm::radians(camera.GetPitch()));
  lookDir.z = -1 * glm::sin(glm::radians(camera.GetYaw())) *
              glm::cos(glm::radians(camera.GetPitch()));
  camera.CameraLookAt(glm::normalize(lookDir));
  // std::cout << lookDir.x <<  " " << lookDir.y << " " << lookDir.z <<
  // std::endl; std::cout << camera.GetYaw() << " " << camera.GetPitch() <<
  // std::endl;
}

void TestLighting::Render() {
  m_Shader->Bind();
  m_Shader->setUniformMat4f("u_Model", m_Model);
  m_Shader->setUniformMat4f("u_Projection", m_Projection);
  m_Shader->setUniformVec3("u_CameraPosition", camera.GetPosition());
  camera.FitNSetViewMatrix(*m_Shader);
  m_vertArray->Bind();
  m_indexBuffer->Bind();
  m_Texture->Bind(0);
  Renderer *renderer = Renderer::GetRenderer();
  renderer->Clear();
  renderer->Draw(*m_vertArray, *m_indexBuffer, *m_Shader);
}
TestLighting::~TestLighting() {
  delete m_vertBuffer;
  delete m_indexBuffer;
  delete m_vertArray;
  delete m_Texture;
}

void TestLighting::ImGuiRender() {
  ImGui::Text("%s", GetName());
  ImGui::SliderFloat("sensitivity", &m_CameraSensitivity, 0.0f, 10.0f);
  ImGui::SliderFloat("Walk Speed", &m_CameraWalkSpeed, 0.0f, 10.0f);
}
