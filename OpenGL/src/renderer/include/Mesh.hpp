#include "IndexBuffer.hpp"
#include "Shaders.hpp"
#include "VertexBuffer.hpp"
#include <string>
#include <vector>
#include <glm/glm.hpp>
struct Vertex{
  glm::vec3 Position;
  glm::vec3 Normal;
  std::vector<glm::vec2> TextureCoordinates;
};
struct Texture2D {
  unsigned int id;
  std::string type;
};
class Mesh {
public:
  // mesh data
  std::vector<Vertex> m_Vertices;
  std::vector<unsigned int> m_Indices;
  std::vector<Texture2D> m_Textures;
  VertexBuffer m_VertexBuffer;
  IndexBuffer m_IndexBuffer;
  Mesh(const std::vector<Vertex> &vertices,const std::vector<unsigned int> &indices,const std::vector<Texture2D>& textures);
  void Draw(Shader &shader);
private:
  // render data
  unsigned int VAO, VBO, EBO;
  void setupMesh();
};
