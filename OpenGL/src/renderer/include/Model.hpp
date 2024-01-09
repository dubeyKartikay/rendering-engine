#ifndef MODEL
#define MODEL

#include "Mesh.hpp"
#include "Shaders.hpp"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <filesystem>
#include <unordered_set>
class Model {
private:
  std::vector<Mesh> m_Meshes;
  std::filesystem::path m_ModelDirectory;
  void LoadModel(const std::filesystem::path &path);
  void ProcessNode(aiNode *node, const aiScene *scene);
  Mesh ProcessMesh(aiMesh *mesh, const aiScene *scene);
  void LoadTextures(std::vector<MeshTexture> & textureArray,aiMaterial *mat, aiTextureType type,
                                        const std::string & typeName);
  std::unordered_set<std::string> m_LoadedTextures;
public:
  Model(const std::filesystem::path &path);
  void Draw(Shader &shader);
};

#endif // !MODEL
