#ifndef VERTEX_BUFFER
#define VERTEX_BUFFER

class VertexBuffer {
private:
  unsigned int m_RenderId;
  unsigned int m_Size;
public:
  VertexBuffer(const void *data, unsigned int size);
  ~VertexBuffer();
  void Bind() const;
  void Unbind() const;
  unsigned int GetCount() const {
    return m_Size;
  }
};
#endif // !VERTEX_BUFFER
