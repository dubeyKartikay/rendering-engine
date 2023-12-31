#ifndef TESTFRAME
#define TESTFRAME
#include <Test.hpp>
#include <vector>


class TestFrame :public Test{
  private:
    std::vector<Test *> tests;
    Test* currTest;
  public:
  TestFrame(){};
   void AddTest(Test * newTest);  
   void Render() override;
   void ImGuiRender() override;
};
#endif // !TESTFRAME

