#include "Mesh.hpp"
#include "Texture2D.hpp"
#include <Model.hpp>
#include <assimp/material.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <glm/glm.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

Model::Model(const std::filesystem::path &path) { LoadModel(path); }
void Model::LoadModel(const std::filesystem::path &path) {
  Assimp::Importer importer;
  const aiScene *scene =
      importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
  if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||
      !scene->mRootNode) {
    std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
    throw std::runtime_error("Unable to load Model at: " + path.string());
  }

  m_ModelDirectory = path.parent_path();
  ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode *node, const aiScene *scene) {
  for (size_t i = 0; i < node->mNumMeshes; i++) {
    aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
    m_Meshes.push_back(ProcessMesh(mesh, scene));
  }

  for (size_t i = 0; i < node->mNumChildren; i++) {
    ProcessNode(node->mChildren[i], scene);
  }
}
glm::vec2 aiVectorToGlm2D(const aiVector3D &aivec3d) {
  return glm::vec2(aivec3d.x, aivec3d.y);
}
glm::vec3 aiVectorToGlm(const aiVector3D &aivec3d) {
  return glm::vec3(aivec3d.x, aivec3d.y, aivec3d.z);
}
Mesh *Model::ProcessMesh(aiMesh *mesh, const aiScene *scene) {
  std::vector<Vertex> meshVertices;
  std::vector<unsigned int> meshIndcies;
  std::vector<MeshTexture> meshMaterial;
  for (size_t i = 0; i < mesh->mNumVertices; i++) {
    Vertex vertex;
    vertex.Position = aiVectorToGlm(mesh->mVertices[i]);
    vertex.Normal = mesh->HasNormals() ? aiVectorToGlm(mesh->mNormals[i])
                                       : glm::vec3(0.0f, 0.0f, 0.0f);
    vertex.TextureCoordinates =
        mesh->mTextureCoords[0] ? aiVectorToGlm2D(mesh->mTextureCoords[0][i])
                                : glm::vec2(0.0f, 0.0f);
    meshVertices.push_back(vertex);
  }

  for (size_t i = 0; i < mesh->mNumFaces; i++) {
    for (size_t j = 0; j < mesh->mFaces[i].mNumIndices; j++) {
      meshIndcies.push_back(mesh->mFaces[i].mIndices[j]);
    }
  }

  if (mesh->mMaterialIndex >= 0) {
    aiMaterial *mat = scene->mMaterials[mesh->mMaterialIndex];
    LoadTextures(meshMaterial, mat, aiTextureType_DIFFUSE, "texture_diffuse");
    LoadTextures(meshMaterial, mat, aiTextureType_SPECULAR, "texture_specular");
  }
  return new Mesh(meshVertices, meshIndcies, meshMaterial);
}
void Model::LoadTextures(std::vector<MeshTexture> &textureArray,
                         aiMaterial *mat, aiTextureType type,
                         const std::string &typeName) {

  for (size_t i = 0; i < mat->GetTextureCount(type); i++) {
    aiString str;
    mat->GetTexture(type, i, &str);
    if (m_LoadedTextures.find(str.C_Str()) != m_LoadedTextures.end())
      continue;
    std::filesystem::path textureDirectory;
    textureDirectory.append(m_ModelDirectory.c_str()).append(str.C_Str());
    std::cout << textureDirectory << std::endl;
    textureArray.push_back({new Texture2D(textureDirectory), typeName});
    m_LoadedTextures.insert(str.C_Str());
  }
}

void Model::Draw(Shader &shader) const {
  for (Mesh *mesh : m_Meshes) {
    mesh->Draw(shader);
  }
}

Model::~Model() {
  std::cout << "Model Destructor" << std::endl;
  for (auto p : m_Meshes) {
    delete p;
  }
  m_Meshes.clear();
}
