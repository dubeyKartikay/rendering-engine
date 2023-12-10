#ifndef VERTEX_ARRAY
#define VERTEX_ARRAY
#include<VertexBuffer.hpp>
#include <VertexBufferLayout.hpp>
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
