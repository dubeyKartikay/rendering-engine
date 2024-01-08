#include "TestTexture2D.hpp"
#include "IndexBuffer.hpp"
#include "Renderer.hpp"
#include "Shaders.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "vendor/imgui/imgui.h"
#include <VertexBufferLayout.hpp>
#include <VertexBuffer.hpp>
#include <cstring>

TestTexture2D::TestTexture2D(){
 m_Shader = new Shader(SHADER_DIR "TestTexture2D.shader");
float positions[] ={
  -0.5f,0.5f,0.0f,1.0f,
  0.5f,0.5f,1.0f,1.0f,
  0.5f,-0.5f,1.0f,0.0f,
  -0.5f,-0.5f,0.0f,0.0f
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
 layout.Push<float>(2);
 m_vertArray->AddBuffer(*m_vertBuffer, layout);
 strcpy(m_texturePath, SHADER_DIR "background.png");
 m_Texture = new Texture2D(m_texturePath);
}
void TestTexture2D::Render(){
  m_Shader->Bind();
  m_vertArray->Bind();
  m_indexBuffer->Bind();
  m_Texture->Bind(0);
  m_Shader->setUniform1i("u_Texture",0);
  Renderer * renderer = Renderer::GetRenderer();
  renderer->Clear();
  renderer->Draw(*m_vertArray,*m_indexBuffer, *m_Shader);
}

void TestTexture2D::ImGuiRender(){
}

TestTexture2D::~TestTexture2D(){
 delete m_vertBuffer;
 delete m_indexBuffer;
 delete m_vertArray;
 delete m_Texture;
}
