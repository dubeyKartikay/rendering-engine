#ifndef TESTFRAME
#define TESTFRAME
#include "Renderer.hpp"
#include <Test.hpp>
#include <vector>

class TestFrame : public Test {
private:
  std::vector<Test *> m_Tests;
  Test *m_CurrTest;

public:
  TestFrame();
  void AddTest(Test *newTest);
  void Update(float deltaTime = 1.0f) override;
  void Render() override;
  void ImGuiRender() override;
  void TestFrameRender();
  void TestFrameImGuiRender();
  void Clear(){Renderer::GetRenderer()->Clear();};
  ~TestFrame();
};
#endif // !TESTFRAME
