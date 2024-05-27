#include "vendor/imgui/imgui.h"
#include <TestFrame.hpp>
#include <iostream>
TestFrame::TestFrame() : m_CurrTest(nullptr) {}

void TestFrame::AddTest(Test *newTest) { m_Tests.push_back(newTest); }
void TestFrame::Update(float deltaTime) {
  if (m_CurrTest)
    m_CurrTest->Update(deltaTime);
}
void TestFrame::Render() {
  if (!m_CurrTest) {
    TestFrameRender();
    return;
  }
  m_CurrTest->Render();
}
void TestFrame::ImGuiRender() {
  TestFrameImGuiRender();
  if (m_CurrTest) {
    m_CurrTest->ImGuiRender();
  }
}
void TestFrame::TestFrameRender() {}
void TestFrame::TestFrameImGuiRender() {
  if (ImGui::BeginCombo("Options",
                        m_CurrTest ? m_CurrTest->GetName() : "Select Test")) {

    for (int i = 0; i < m_Tests.size(); i++) {
      bool isSelected = (m_CurrTest == m_Tests[i]);
      if (ImGui::Selectable(m_Tests[i]->GetName(), isSelected)) {
        m_CurrTest = m_Tests[i];
        std::cout << "message " << i << std::endl;
      }

      if (isSelected)
        ImGui::SetItemDefaultFocus();
    }
    ImGui::EndCombo();
  }
}
TestFrame::~TestFrame() {
  std::cout << "TestFrame destructor called" << std::endl;
  for (auto p : m_Tests) {
    delete p;
  }
  m_Tests.clear();
  m_CurrTest = nullptr;
}
