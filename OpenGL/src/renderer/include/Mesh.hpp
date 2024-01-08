#ifndef MESH
#define MESH
#include "IndexBuffer.hpp"
#include "Shaders.hpp"
#include "Texture2D.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include <string>
#include <vector>
#include <glm/glm.hpp>
struct Vertex{
  glm::vec3 Position;
  glm::vec3 Normal;
  glm::vec2 TextureCoordinates;
};
struct MeshTexture {
  Texture2D texture;
  std::string type;
};
class Mesh {
public:
  // mesh data
  Mesh(const std::vector<Vertex> &vertices,const std::vector<unsigned int> &indices,const std::vector<MeshTexture>& textures);
  void Draw(Shader &shader);
private:
  std::vector<Vertex> m_Vertices;
  std::vector<unsigned int> m_Indices;
  std::vector<MeshTexture> m_Textures;
  VertexBuffer m_VertexBuffer;
  VertexArray m_VertexArray;
  IndexBuffer m_IndexBuffer;
};
#endif // !MESH
