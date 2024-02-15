#include <Light.hpp>
#include <glm/glm.hpp>

PointLight::PointLight(const glm::vec3 &position, const glm::vec3 &diffuse)
    : position(position), ambient(0.1f * diffuse), diffuse(diffuse),
      specular(1.0f), constant(1.0f), linear(0.07f), quadratic(0.032f) {}

PointLight::PointLight(const glm::vec3 &position, const glm::vec3 &diffuse,
                       const glm::vec3 &specular)
    : position(position), ambient(0.1f * diffuse), diffuse(diffuse),
      specular(specular), constant(1.0f), linear(0.07f), quadratic(0.032f) {}

PointLight::PointLight(const glm::vec3 &position, const glm::vec3 &diffuse,
                       const glm::vec3 &specular, const glm::vec3 &ambient)
    : position(position), ambient(ambient), diffuse(diffuse),
      specular(specular), constant(1.0f), linear(0.07f), quadratic(0.032f) {}

PointLight::PointLight(const glm::vec3 &position, const glm::vec3 &diffuse,
                       const glm::vec3 &specular, const glm::vec3 &ambient,
                       const float &constant,
                       const float &linear,
                       const float &quadratic)
    : position(position), ambient(ambient), diffuse(diffuse),
      specular(specular), constant(constant), linear(linear),
      quadratic(quadratic) {}

DirectionalLight::DirectionalLight(const glm::vec3 &direction, const glm::vec3 &diffuse)
      : direction(glm::normalize(direction)), ambient(0.1f * diffuse), diffuse(diffuse), specular(1.0f) {}

DirectionalLight::DirectionalLight(const glm::vec3 &direction, const glm::vec3 &diffuse, const glm::vec3 &specular)
      : direction(glm::normalize(direction)), ambient(0.1f * diffuse), diffuse(diffuse), specular(specular) {}

DirectionalLight::DirectionalLight(const glm::vec3 &direction, const glm::vec3 &diffuse, const glm::vec3 &specular, const glm::vec3 &ambient)
      : direction(glm::normalize(direction)), ambient(ambient), diffuse(diffuse), specular(specular) {}
