#include "Renderer.hpp"
#include <Mesh.hpp>

Mesh::Mesh(const std::vector<Vertex> &vertices,
           const std::vector<unsigned int> &indices,
           const std::vector<MeshTexture> &textures)
    : m_VertexBuffer(vertices.data(), vertices.size() * sizeof(Vertex)),
      m_IndexBuffer(indices.data(), indices.size()) {
  m_Vertices = vertices;
  m_Indices = indices;
  m_Textures = textures;
  VertexBufferLayout vblayout;
  vblayout.Push<float>(3);
  vblayout.Push<float>(3);
  vblayout.Push<float>(2);
  m_VertexArray.AddBuffer(m_VertexBuffer, vblayout);
}
void Mesh::Draw(Shader &shader) {
  unsigned int countDiffuse = 1;
  unsigned int countSpecular = 1;
  for (int i = 0; i < m_Textures.size(); i++) {
    m_Textures[i].texture.Bind(i);
    std::string number;
    std::string name = m_Textures[i].type;
    if (name == "texture_diffuse")
      number = std::to_string(countDiffuse++);
    else if (name == "texture_specular")
      number = std::to_string(countSpecular++);
    shader.setUniform1i("material." + name + number, i);
  }
  Renderer::GetRenderer()->Draw(m_VertexArray, m_IndexBuffer, shader);
  m_VertexArray.Unbind();
  
}
