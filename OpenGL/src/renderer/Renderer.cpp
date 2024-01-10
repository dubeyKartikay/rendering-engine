#include "Model.hpp"
#include <Renderer.hpp>
void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib,
                    const Shader &shader) const {
  va.Bind();
  ib.Bind();
  shader.Bind();
  glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
void Renderer::Draw(const Model & model,Shader & shader) const{
  shader.Bind();
  model.Draw(shader);
}
void Renderer::EnableDepthTesting() const { glEnable(GL_DEPTH_TEST); }

void Renderer::Clear() const {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
Renderer::Renderer(){}
Renderer * Renderer::renderer = nullptr;
