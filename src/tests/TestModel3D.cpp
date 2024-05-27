#include "Input.hpp"
#include "vendor/imgui/imgui.h"
#include <Renderer.hpp>
#include <TestModel3D.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <iostream>

TestModel3D::TestModel3D()
    : m_ModelMatrix(1.0f), m_Projection(1.0f), m_Translate(0.0f, 0.0f, -3.0f),
       m_CameraSensitivity(1.0f),
      m_CameraWalkSpeed(1.0f), m_Fov(45.0f) {
  m_Shader = new Shader(SHADER_DIR "TestModel3D.shader");
  std::cout << "Loading Model" << std::endl;
  m_Model = new Model(SHADER_DIR "backpack/backpack.obj");
  std::cout << "Model Loaded" << std::endl;
  Renderer::GetRenderer()->EnableDepthTesting();
  m_Projection =
      glm::perspective(glm::radians(m_Fov), 800.0f / 600.0f, 0.1f, 100.0f);
  m_ModelMatrix = glm::translate(m_ModelMatrix, m_Translate);
  m_Shader->Bind();
  m_Shader->setUniformMat4f("u_Projection", m_Projection);
  m_Shader->setUniformMat4f("u_Model", m_ModelMatrix);
  m_Shader->Unbind();
  Input::SetScrollCallback([this](double xOff, double yOff) {
    m_Fov -= yOff;
    if(m_Fov < 1.0f) m_Fov = 1.0f;
    if(m_Fov > 45.0f) m_Fov = 45.0f;
    m_Projection =
        glm::perspective(glm::radians(m_Fov), 800.0f / 600.0f, 0.1f, 100.0f);

  });
}

void TestModel3D::Update(float deltaTime) {
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
}

void TestModel3D::Render() {
  m_Shader->Bind();
  m_Shader->setUniformMat4f("u_Projection", m_Projection);
  camera.FitNSetViewMatrix(*m_Shader);
  Renderer *renderer = Renderer::GetRenderer();
  renderer->Clear();
  renderer->Draw(*m_Model,*m_Shader);
}
TestModel3D::~TestModel3D() {
  delete m_Model;
  delete m_Shader;
}

void TestModel3D::ImGuiRender() {
  ImGui::Text("%s", GetName());
  ImGui::SliderFloat("sensitivity", &m_CameraSensitivity, 0.0f, 10.0f);
  ImGui::SliderFloat("Walk Speed", &m_CameraWalkSpeed, 0.0f, 10.0f);
}
