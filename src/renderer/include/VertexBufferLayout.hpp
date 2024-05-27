#include <vector>
#include <GL/gl.h>
#include <cassert>
#ifndef VERTEX_BUFFER_LAYOUT
#define VERTEX_BUFFER_LAYOUT
#define assertm(exp, msg) assert(((void)msg, exp))
struct VertexBufferAttribs {
  unsigned int type;
  unsigned int count;
  unsigned int normailzed;

  static unsigned int GetTypeSize(unsigned int type) {
    switch (type) {
    case GL_FLOAT:
      return sizeof(GLfloat);
    case GL_UNSIGNED_INT:
      return sizeof(GLuint);
    case GL_UNSIGNED_BYTE:
      return sizeof(GLubyte);
    }
    assertm(false, "VertexBufferAttribs: Unsupported Type");
    return 0;
  }
};
class VertexBufferLayout {
private:
  std::vector<VertexBufferAttribs> m_AttribsBlueprint;
  unsigned int m_Stride;
public:
    VertexBufferLayout(): m_Stride(0){};
  template <typename T> void Push(unsigned int count);
  const std::vector<VertexBufferAttribs> & GetAttribsBlueprint() const {return m_AttribsBlueprint;} 
  const unsigned int GetStride() const {return m_Stride;} 
};
template <> void VertexBufferLayout::Push<float>(unsigned int count);
template <> void VertexBufferLayout::Push<unsigned int>(unsigned int count);
template <> void VertexBufferLayout::Push<unsigned char>(unsigned int count);

#endif // !VERTEX_BUFFER_LAYOUT
