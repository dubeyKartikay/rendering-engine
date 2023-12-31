#include "IndexBuffer.hpp"
#include "Renderer.hpp"
#include "Shaders.hpp"
#include "TestCube3D.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "vendor/imgui/imgui.h"
#include <GLFW/glfw3.h>
#include <VertexBuffer.hpp>
#include <VertexBufferLayout.hpp>
#include <cstring>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>

TestCube3D::TestCube3D() {
  m_Shader = new Shader(SHADER_DIR "TestRect2D.shader");
  float positions[] = {-0.5f,
                       0.5f,
                       0.5f,
                       0.0f,
                       1.0f,
                       0.5f,
                       0.5f,
                       0.5f,
                       1.0f,
                       1.0f,
                       0.5f,
                       -0.5f,
                       0.5f,
                       1.0f,
                       0.0f,
                       -0.5f,
                       -0.5f,
                       0.5f,
                       0.0f,
                       0.0f

                           - 0.5f,
                       0.5f,
                       -0.5f,
                       0.0f,
                       1.0f,
                       0.5f,
                       0.5f,
                       -0.5f,
                       1.0f,
                       1.0f,
                       0.5f,
                       -0.5f,
                       -0.5f,
                       1.0f,
                       0.0f,
                       -0.5f,
                       -0.5f,
                       -0.5f,
                       0.0f,
                       0.0f};
  unsigned int index[] = {0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4, 0, 4, 1, 4, 5, 1,
                          1, 5, 6, 1, 2, 6, 0, 4, 7, 0, 3, 7, 7, 3, 6, 3, 6, 2};

  
  m_Model = glm::mat4(1.0f);
  m_Model = glm::rotate(m_Model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
  glm::mat4 view = glm::mat4(1.0f);
  view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
  glm::mat4 projection =
      glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);
  
  m_vertBuffer = new VertexBuffer(positions, 8 * 2 * sizeof(float));
  m_vertArray = new VertexArray();
  m_indexBuffer = new IndexBuffer(index, 3 * 2 * 6);
  VertexBufferLayout layout;
  layout.Push<float>(3);
  layout.Push<float>(2);
  m_vertArray->AddBuffer(*m_vertBuffer, layout);
  
  strcpy(m_texturePath, SHADER_DIR "background.png");
  m_Texture = new Texture(m_texturePath);
  Renderer::GetRenderer()->EnableDepthTesting();
}
void TestCube3D::Update(){
 m_Model = glm::rotate(m_Model, (float)glfwGetTime()*glm::radians(50.0f), glm::vec3(0.5f,1.0f,0.0f)); 
}
void TestCube3D::Render() {

  m_Shader->Bind();
  m_vertArray->Bind();
  m_indexBuffer->Bind();
  m_Texture->Bind(0);
  m_Shader->setUniform1i("u_Texture", 0);
  m_Shader->setUniformMat4f("u_Model", m_Model);
  Renderer *renderer = Renderer::GetRenderer();
  renderer->Clear();
  renderer->Draw(*m_vertArray, *m_indexBuffer, *m_Shader);
}

void TestCube3D::ImGuiRender() {}

TestCube3D::~TestCube3D() {
  delete m_vertBuffer;
  delete m_indexBuffer;
  delete m_vertArray;
  delete m_indexBuffer;
  delete m_Texture;
}
