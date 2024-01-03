#ifndef RENDERER
#define RENDERER
#include <Shaders.hpp>
#include <VertexArray.hpp>
#include <IndexBuffer.hpp>

class Renderer{
  private:
    Renderer();
    static Renderer * renderer;
  public:
    void EnableDepthTesting()const;
    void Draw(const VertexArray& va, const IndexBuffer & ib, const Shader & shader) const;
    void Clear() const;
    Renderer(const Renderer& obj) = delete;
    static Renderer * GetRenderer(){
        if(!renderer){
          renderer = new Renderer();
        }
        return renderer;
    }
    static void Destroy(){
      delete renderer;
    }
};
#endif // DEBUG
