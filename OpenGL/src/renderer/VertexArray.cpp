#include <GL/glew.h>
#include <GLUtils.hpp>
#include <VertexArray.hpp>
#include <iostream>
VertexArray::VertexArray() { glGenVertexArrays(1, &m_RendererId); }
void VertexArray::Bind() const { glBindVertexArray(m_RendererId); }
void VertexArray::Unbind() const { glBindVertexArray(0); }
VertexArray::~VertexArray() { glDeleteVertexArrays(1, &m_RendererId); }
void VertexArray::AddBuffer(VertexBuffer &vb, VertexBufferLayout &layout) {
  Bind();
  vb.Bind();
  auto &vertexAttribsBlueprint = layout.GetAttribsBlueprint();
  unsigned int offset = 0;
  for (unsigned int i = 0; i < vertexAttribsBlueprint.size(); i++) {
    auto &element = vertexAttribsBlueprint[i];
    glEnableVertexAttribArray(i);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
    glVertexAttribPointer(
        i, element.count, element.type, element.normailzed, layout.GetStride(),
        (const void *)offset); // The most ridiculus thing about OpenGL, Storing
                               // an interger as a const void pointer??????
#pragma GCC diagnostic pop
    offset += element.count * VertexBufferAttribs::GetTypeSize(element.type);
  }
}
