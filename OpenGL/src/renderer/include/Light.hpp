#ifndef LIGHT
#define LIGHT
#include <vector>
#include <vendor/glm/glm.hpp>
struct DirectionalLight{

};
struct PointLight{

};

// struct SpotLight{};
class Light{
  private:
    std::vector<DirectionalLight> m_DirectionalLight;
    std::vector<PointLight> m_PointLight;

  public:

    Light();
    ~Light();
    void AddDirectionalLight(glm::vec3 normalisedDirection, float intensity);
    void AddPointLight(glm::vec3 normalisedLightPosition, float intensity);
    // void AddSpotLight();
    const std::vector<DirectionalLight> & getDirectionalLights();
    const std::vector<PointLight> & getPointLights();
};


#endif // !LIGHT
