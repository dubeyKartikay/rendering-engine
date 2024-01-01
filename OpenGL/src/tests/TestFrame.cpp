#include<iostream>
#include "vendor/imgui/imgui.h"
#include <TestFrame.hpp>
#include <typeinfo>

TestFrame::TestFrame() : m_CurrTest(nullptr) {}

void TestFrame::AddTest(Test *newTest) { m_Tests.push_back(newTest); }
void TestFrame::Render() {
  if (!m_CurrTest) {
    TestFrameRender();
    return;
  }
  m_CurrTest->Update();
  m_CurrTest->Render();
}
void TestFrame::ImGuiRender() {
  if (!m_CurrTest) {
    TestFrameImGuiRender();
    return;
  }
  m_CurrTest->ImGuiRender();
}
void TestFrame::TestFrameRender() {}
void TestFrame::TestFrameImGuiRender() {
  if (ImGui::BeginCombo("Options", typeid(m_CurrTest).name())) {
    for (int i = 0; i < m_Tests.size(); i++) {
      bool isSelected = (m_CurrTest == m_Tests[i]);
      if (ImGui::Selectable(typeid(m_Tests[i]).name(), isSelected)){
        m_CurrTest=m_Tests[i];
      std::cout << "message " << i  << std::endl;
      }
        
      if (isSelected)
        ImGui::SetItemDefaultFocus();
    }
    ImGui::EndCombo();
  }
}
TestFrame::~TestFrame(){
  for(auto p : m_Tests){
    delete p;
  }
  m_Tests.clear();
  m_CurrTest=NULL;
}
