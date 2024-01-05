#include <Camera.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/quaternion_geometric.hpp>
#include <limits>

Camera::Camera()
    : m_CameraPos(0.0f), m_CameraFront(0.0f, 0.0f, -1.0f),
      m_CameraUp(0.0f, 1.0f, 0.0f),
      m_CameraRight(glm::normalize(glm::cross(m_CameraFront, m_CameraUp))),
      m_ViewMatrix(1.0f), m_Yaw(90.0f), m_Pitch(0.0f), m_LowerYawClamp(-std::numeric_limits<float>::infinity()),
      m_UpperYawClamp(std::numeric_limits<float>::infinity()), m_LowerPitchClamp(-90.0f),
      m_UpperPitchClamp(90.0f) {}

void Camera::IncrementYaw(float increment){
  m_Yaw += increment;
  if(m_Yaw > m_UpperYawClamp) m_Yaw = m_UpperYawClamp;
  else if (m_Yaw < m_LowerYawClamp) m_Yaw = m_LowerYawClamp;
}
void Camera::IncrementPitch(float increment){
  m_Pitch += increment;
  if(m_Pitch > m_UpperPitchClamp) m_Pitch = m_UpperPitchClamp;
  else if (m_Pitch < m_LowerPitchClamp) m_Pitch = m_LowerPitchClamp;
}

void Camera::Translate(const glm::vec3 & direction){
  m_CameraPos += direction.x*m_CameraRight + direction.y*m_CameraUp - direction.z*m_CameraFront;
}

void Camera::FitViewMatrix(){
  m_CameraRight = glm::normalize(glm::cross(m_CameraFront, m_CameraUp));
  m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp); 
}

void Camera::SetViewMatrix(Shader & shader,const std::string & viewMatrixUniformName){
  shader.setUniformMat4f(viewMatrixUniformName,m_ViewMatrix);
}

void Camera::FitNSetViewMatrix(Shader & shader,const std::string & viewMatrixUniformName){
  FitViewMatrix();
  SetViewMatrix(shader,viewMatrixUniformName);
}
