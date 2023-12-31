#ifndef TESTFRAME
#define TESTFRAME
#include <Test.hpp>
#include <vector>

class TestFrame : public Test {
private:
  std::vector<Test *> m_Tests;
  Test *m_CurrTest;

public:
  TestFrame();
  void AddTest(Test *newTest);
  void Render() override;
  void ImGuiRender() override;
  void TestFrameRender();
  void TestFrameImGuiRender();
  void Clear(){};
  ~TestFrame();
};
#endif // !TESTFRAME
