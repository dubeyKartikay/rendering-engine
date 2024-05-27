#include "Renderer.hpp"
#include <Mesh.hpp>
#include <iostream>

Mesh::Mesh(const std::vector<Vertex> &vertices,
           const std::vector<unsigned int> &indices,
           const std::vector<MeshTexture> &textures)
    : m_VertexBuffer(&vertices[0], vertices.size() * sizeof(Vertex)),
      m_IndexBuffer(&indices[0], indices.size()) {
  m_Textures = textures;
  VertexBufferLayout vblayout;
  vblayout.Push<float>(3);
  vblayout.Push<float>(3);
  vblayout.Push<float>(2);
  m_VertexArray.AddBuffer(m_VertexBuffer, vblayout);
}
void Mesh::Draw(Shader &shader) const {
  unsigned int countDiffuse = 1;
  unsigned int countSpecular = 1;
  for (int i = 0; i < m_Textures.size(); i++) {
    m_Textures[i].texture->SetActive(i);
    std::string number;
    std::string name = m_Textures[i].type;
    if (name == "texture_diffuse") {
      number = std::to_string(countDiffuse++);
    } else if (name == "texture_specular") {
      number = std::to_string(countSpecular++);
    }
    shader.setUniform1i(name + number, i);
    m_Textures[i].texture->Bind(i);
  }
  Renderer::GetRenderer()->Draw(m_VertexArray, m_IndexBuffer, shader);
}

Mesh::~Mesh() {
  for (auto &p : m_Textures) {
    delete p.texture;
  }
  m_Textures.clear();
}
