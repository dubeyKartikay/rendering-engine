#ifndef LIGHT
#define LIGHT
#include <vendor/glm/glm.hpp>
struct DirectionalLight{
  glm::vec3 direction;
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  DirectionalLight(const glm::vec3 &direction, const glm::vec3 &diffuse);

  DirectionalLight(const glm::vec3 &direction, const glm::vec3 &diffuse, const glm::vec3 &specular);

  DirectionalLight(const glm::vec3 &direction, const glm::vec3 &diffuse, const glm::vec3 &specular, const glm::vec3 &ambient);
};
struct PointLight{

  glm::vec3 position;
  glm::vec3 ambient;
  glm::vec3 diffuse;
  glm::vec3 specular;
  float constant;
  float linear;
  float quadratic;
  PointLight(const glm::vec3 & position, const glm::vec3 & diffuse);
  PointLight(const glm::vec3 & position, const glm::vec3 &diffuse, const glm::vec3 &specular);
  PointLight(const glm::vec3 & position, const glm::vec3 &diffuse, const glm::vec3 &specular, const glm::vec3 &ambient);
  PointLight(const glm::vec3 & position, const glm::vec3 &diffuse, const glm::vec3 &specular, const glm::vec3 &ambient, const float &constant,const float &linear,const float & quadratic);
};

#endif // !LIGHT
