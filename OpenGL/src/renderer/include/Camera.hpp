#include "Shaders.hpp"
#include <glm/glm.hpp>
#ifndef CAMERA
#define CAMERA
class Camera{
  private:
    glm::vec3 m_CameraPos;
    glm::vec3 m_CameraFront;
    glm::vec3 m_CameraUp;
    glm::vec3 m_CameraRight;
    glm::mat4 m_ViewMatrix;
    float m_Yaw;
    float m_Pitch;
    float m_LowerYawClamp;
    float m_UpperYawClamp;
    float m_LowerPitchClamp;
    float m_UpperPitchClamp;
  public:
    Camera();
    void FitViewMatrix();
    void SetViewMatrix(Shader & shader,const std::string & viewMatrixUniformName = "u_View");
    glm::mat4 & GetViewMatrix() {return m_ViewMatrix;}
    void FitNSetViewMatrix(Shader & shader,const std::string & viewMatrixUniformName = "u_View");
    void Translate(const glm::vec3 &direction);
    void IncrementYaw(float increment);
    void IncrementPitch(float increment);
    Camera * SetLowerYawClamp(float lowerYaw) {m_LowerYawClamp = lowerYaw; return this;}
    Camera * SetUpperYawClamp(float upperYaw) {m_UpperYawClamp = upperYaw; return this;}
    Camera * SetLowerPitchClamp(float lowerPitch) {m_LowerPitchClamp = lowerPitch; return this;}
    Camera * SetUpperPitchClamp(float upperPitch) {m_UpperPitchClamp = upperPitch; return this;}
    void CameraLookAt(const glm::vec3  &direction) {m_CameraFront = direction;}
    
};
#endif // !CAMERA
