#include<VertexBuffer.hpp>
#include <VertexBufferLayout.hpp>
#ifndef VERTEX_ARRAY
#define VERTEX_ARRAY

class VertexArray{
  private:
    unsigned int m_RendererId;
  public:
    VertexArray();
    ~VertexArray();
    void AddBuffer(VertexBuffer &vb, VertexBufferLayout & layout);
    void Bind() const;
    void Unbind() const;
};

#endif // !VERTEX_ARRAY
