#include <GL/glew.h>
#include <IndexBuffer.hpp>

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) : m_Count(count) {
  glGenBuffers(1, &m_RenderId);
  glBindBuffer(GL_ARRAY_BUFFER, m_RenderId);
  glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int) * count, data,
               GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &m_RenderId); }
void IndexBuffer::Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId); }
void IndexBuffer::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
