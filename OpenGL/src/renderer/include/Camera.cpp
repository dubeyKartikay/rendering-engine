#include <Camera.hpp>
#include <glm/ext/quaternion_geometric.hpp>

Camera::Camera()
    : m_CameraPos(0.0f), m_CameraFront(0.0f, 0.0f, -1.0f),
      m_CameraUp(0.0f, 1.0f, 0.0f),
      m_CameraRight(glm::normalize(glm::cross(m_CameraUp, m_CameraFront))),
      m_ViewMatrix(1.0f), m_Yaw(90.0f), m_Pitch(0.0f), m_LowerYawClamp(0.0f),
      m_UpperYawClamp(180.0f), m_LowerPitchClamp(-90.0f),
      m_UpperPitchClamp(90.0f) {}


