#include "Shaders.hpp"
#include <glm/glm.hpp>
#ifndef CAMERA
#define CAMERA
class Camera{
  private:
    glm::vec3 m_CameraPos;
    glm::vec3 m_Target;
    float m_Yaw;
    float m_Pitch;
    float m_NegYawClamp;
    float m_PosYawClamp;
    float m_NegPitchClamp;
    float m_PosPitchClamp;
  public:
    Camera();
    void Fit();
    void FitTransform(Shader & shader);
    void Translate(const glm::vec3 &direction, float speed);
    void IncrementYaw(float increment);
    void IncrementPitch(float increment);
    
};
#endif // !CAMERA
