#ifndef LIGHT
#define LIGHT
#include <vector>
#include <vendor/glm/glm.hpp>
struct DirectionalLight{
  glm::vec3 direction;
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;

};
struct PointLight{

  glm::vec3 position;
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  float constant;
  float linear;
  float quadratic;
};

// struct SpotLight{};
class Light{
  private:
    std::vector<DirectionalLight> m_DirectionalLight;
    std::vector<PointLight> m_PointLight;

  public:

    Light();
    ~Light();
    void AddDirectionalLight(glm::vec3 normalisedDirection, glm::vec3 diffuse);
    void AddDirectionalLight(glm::vec3 normalisedDirection, glm::vec3 diffuse, glm::vec3 specular);
    void AddDirectionalLight(glm::vec3 normalisedDirection, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 ambient);
    void AddPointLight(glm::vec3 normalisedLightPosition, glm::vec3 diffuse);
    void AddPointLight(glm::vec3 normalisedLightPosition, glm::vec3 diffuse, glm::vec3 specular);
    void AddPointLight(glm::vec3 normalisedLightPosition, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 ambient);
    void AddPointLight(glm::vec3 normalisedLightPosition, glm::vec3 diffuse, glm::vec3 specular, glm::vec3 ambient, float linear, float quadratic, float constant = 1.0f);
    // void AddSpotLight();
    const std::vector<DirectionalLight> & getDirectionalLights();
    const std::vector<PointLight> & getPointLights();
};


#endif // !LIGHT
