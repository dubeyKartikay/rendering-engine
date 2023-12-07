#include <VertexBufferLayout.hpp>
template <> void VertexBufferLayout::Push<float>(unsigned int count) {
  m_AttribsBlueprint.push_back({GL_FLOAT, count, GL_FALSE});
  m_Stride += count * VertexBufferAttribs::GetTypeSize(GL_FLOAT);
}
template <> void VertexBufferLayout::Push<unsigned int>(unsigned int count) {
  m_AttribsBlueprint.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
  m_Stride += count * VertexBufferAttribs::GetTypeSize(GL_UNSIGNED_INT);
}
template <> void VertexBufferLayout::Push<unsigned char>(unsigned int count) {
  m_AttribsBlueprint.push_back({GL_UNSIGNED_BYTE, count, GL_FALSE});
  m_Stride += count * VertexBufferAttribs::GetTypeSize(GL_UNSIGNED_BYTE);
}
template <typename T> void VertexBufferLayout::Push(unsigned int count) {
  static_assert(false, "VertexBufferLayout: Unsupported Type");
}
