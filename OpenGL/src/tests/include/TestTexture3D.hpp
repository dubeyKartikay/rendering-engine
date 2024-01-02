#ifndef TESTTEXTURE3D
#define TESTTEXTURE3D
#include <Test.hpp>
class TestTexture3D : public Test {
private:
public:
  TestTexture3D();
  void Render() override;
  void ImGuiRender() override;
  ~TestTexture3D();
  const char * GetName() override {return "TestTexture3D";}
};
#endif 
