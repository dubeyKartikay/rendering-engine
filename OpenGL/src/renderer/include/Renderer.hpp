#ifndef RENDERER
#define RENDERER
#include <Shaders.hpp>
#include <VertexArray.hpp>
#include <IndexBuffer.hpp>

class Renderer{
  private:
     
  public:
    void Draw(const VertexArray& va, const IndexBuffer & ib, const Shader & shader) const;
    void Clear() const;
};

#endif // DEBUG
