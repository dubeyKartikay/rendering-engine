#ifndef TESTCAMERA3D
#define TESTCAMERA3D
#include <Test.hpp>
class TestCamera3D : public Test {
private:
public:
  TestCamera3D();
  void Render() override;
  void ImGuiRender() override;
  ~TestCamera3D();
};
#endif 
