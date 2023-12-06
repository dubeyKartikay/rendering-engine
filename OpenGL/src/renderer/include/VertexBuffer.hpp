#ifndef VERTEX_BUFFER
#define VERTEX_BUFFER

class VertexBuffer {
private:
  unsigned int m_RenderId;

public:
  VertexBuffer(const void *data, unsigned int size);
  ~VertexBuffer();
  void Bind() const;
  void Unbind() const;
};
#endif // !VERTEX_BUFFER
