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
struct Material{
  unsigned int diffuse;
  unsigned int specular;
  float shininess;
  Material(unsigned int tex_diffuse,unsigned int tex_spec , float shine) : diffuse(tex_diffuse), specular(tex_spec), shininess(shine){}
  
};
#endif // !LIGHT
