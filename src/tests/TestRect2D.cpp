#include "IndexBuffer.hpp"
#include "Renderer.hpp"
#include "Shaders.hpp"
#include "VertexArray.hpp"
#include "vendor/imgui/imgui.h"
#include <TestRect2D.hpp>
#include <VertexBufferLayout.hpp>
#include <VertexBuffer.hpp>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
TestRect2D::TestRect2D(): m_rectColor {1.0f,1.0f,1.0f,1.0f} {
 m_Shader = new Shader(SHADER_DIR "TestRect2D.shader");
float positions[] ={
  -0.5f,0.5f,
  0.5f,0.5f,
  0.5f,-0.5f,
  -0.5f,-0.5f
};
unsigned int index[] = {
  0,1,2,
  2,3,0
};

  m_vertBuffer = new VertexBuffer(positions,sizeof(positions));
 m_vertArray = new VertexArray();
 m_indexBuffer = new IndexBuffer(index,6);
 VertexBufferLayout layout;
 layout.Push<float>(2);
 m_vertArray->AddBuffer(*m_vertBuffer, layout);
}
void TestRect2D::Render(){
  m_Shader->Bind();
  m_vertArray->Bind();
  m_indexBuffer->Bind();
  m_Shader->setUniform4f("u_Color", m_rectColor[0], m_rectColor[1],m_rectColor[2],m_rectColor[3]);
  Renderer * renderer = Renderer::GetRenderer();
  renderer->Clear();
  renderer->Draw(*m_vertArray,*m_indexBuffer, *m_Shader);
}

void TestRect2D::ImGuiRender(){
  ImGui::ColorEdit4("Rectangle Color",glm::value_ptr(m_rectColor));
  m_rectColor=glm::normalize(m_rectColor);
}

TestRect2D::~TestRect2D(){
  std::cout<<"TestRect2D destructor called" << std::endl;
 delete m_vertBuffer;
 delete m_indexBuffer;
 delete m_vertArray;
}
