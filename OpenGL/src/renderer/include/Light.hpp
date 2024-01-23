#ifndef LIGHT
#define LIGHT
#include <vendor/glm/glm.hpp>
class Light{
  private:

  public:
    Light();
    ~Light();
    void AddDirectionalLight(glm::vec3 normalisedDirection, float intensity);
    void AddPointLight(glm::vec3 normalisedLightPosition, float intensity);
    void AddSpotLight();
};


#endif // !LIGHT
