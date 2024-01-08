#include <Mesh.hpp>

Mesh::Mesh(const std::vector<Vertex> &vertices,
           const std::vector<unsigned int> &indices,
           const std::vector<Texture2D> &textures)
    : m_VertexBuffer(vertices.data(), vertices.size() * sizeof(Vertex)),
      m_IndexBuffer(indices.data(), indices.size()) {
  m_Vertices = vertices;
  m_Indices = indices;
  m_Textures = textures;
  VertexBufferLayout vblayout;
}
