#include "Input.hpp"
#include "vendor/imgui/imgui.h"
#include <TestCamera3D.hpp>
#include <cstring>
#include <Renderer.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <iostream>
TestCamera3D::TestCamera3D()
    : m_Model(1.0f), m_Projection(1.0f), m_Translate(0.0f, 0.0f, -3.0f),
      m_CubeRoationAxis(1.0f), m_RotationAngle(0.0f) {
  m_Shader = new Shader(SHADER_DIR "TestCube3D.shader");
  float positions[] = {
      // positions          // texture coords
      0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top right
      0.5f,  -0.5f, 0.5f,  1.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.5f,  0.0f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.5f,  0.0f, 1.0f, // top left

      0.5f,  0.5f,  -0.5f, 0.0f, 1.0f, // top right
      0.5f,  -0.5f, -0.5f, 0.0f, 0.0f, // bottom right
      -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, // bottom left
      -0.5f, 0.5f,  -0.5f, 1.0f, 1.0f  // top left
  };
  unsigned int index[] = {0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4, 0, 4, 1, 4, 5, 1,
                          1, 5, 6, 1, 2, 6, 0, 4, 7, 0, 3, 7, 7, 3, 6, 3, 6, 2};

  m_vertBuffer = new VertexBuffer(positions, sizeof(positions));
  m_vertArray = new VertexArray();
  m_indexBuffer = new IndexBuffer(index, 6 * 3 * 2);
  VertexBufferLayout layout;
  layout.Push<float>(3);
  layout.Push<float>(2);
  m_vertArray->AddBuffer(*m_vertBuffer, layout);
  strcpy(m_texturePath, SHADER_DIR "background.png");
  m_Texture = new Texture(m_texturePath);
  Renderer::GetRenderer()->EnableDepthTesting();
  m_Projection =
      glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
  m_Model = glm::translate(m_Model, m_Translate);
  m_Shader->Bind();
  m_Shader->setUniform1i("u_Texture", 0);
  m_Shader->setUniformMat4f("u_Projection", m_Projection);
  m_Shader->setUniformMat4f("u_Model", m_Model);
  m_Shader->Unbind();
}

void TestCamera3D::Update(float deltaTime){
  m_Model = glm::rotate(m_Model, glm::radians(50.0f) * 2 *deltaTime,
                        glm::vec3(0.5f, 1.0f, 0.0f));
  if(Input::GetKeyPressed('w')){
    camera.Translate({0,0,-1.0f*deltaTime});
  }else if ( Input::GetKeyPressed('s') ){
    camera.Translate({0,0,1.0f*deltaTime});
  }else if (Input::GetKeyPressed('a')) {
    camera.Translate({-1.0*deltaTime,0,0});
  }else if (Input::GetKeyPressed('d')) {
    camera.Translate({1.0f*deltaTime,0,0});
  }
}

void TestCamera3D::Render(){
  m_Shader->Bind();
  m_Shader->setUniformMat4f("u_Model", m_Model);
  camera.FitNSetViewMatrix(*m_Shader);
  m_vertArray->Bind();
  m_indexBuffer->Bind();
  m_Texture->Bind(0);
  Renderer *renderer = Renderer::GetRenderer();
  renderer->Clear();
  renderer->Draw(*m_vertArray, *m_indexBuffer, *m_Shader);
}
TestCamera3D::~TestCamera3D(){
  delete m_vertBuffer;
  delete m_indexBuffer;
  delete m_vertArray;
  delete m_Texture;
}

void TestCamera3D::ImGuiRender() {
  ImGui::Text("%s", GetName());
}























