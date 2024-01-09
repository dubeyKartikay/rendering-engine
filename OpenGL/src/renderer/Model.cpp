#include <Model.hpp>
#include <assimp/postprocess.h>
#include <iostream>
#include <stdexcept>

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

void  Model::ProcessNode(aiNode *node, const aiScene *scene){
  for (size_t i = 0; i < node->mNumMeshes; i++) {
    aiMesh * mesh = scene->mMeshes[node->mMeshes[i]];
    m_Meshes.push_back(ProcessMesh(mesh,scene));
  }

  for (size_t i = 0; i < node->mNumChildren; i++) {
    ProcessNode(node->mChildren[i], scene);
  }
}
