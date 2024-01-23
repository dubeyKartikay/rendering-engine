#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec2 v_texCord;
out vec3 v_Normal;
out vec3 v_FragmentPosition;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    v_texCord = aTexCoords;    
    v_FragmentPosition = vec3(u_Model* vec4(aPos,1.0f));
    v_CameraPosition = vec3(u_Model* vec4(v_CameraPosition,1.0f));
    v_Normal = normalize(aNormal);
    gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core

out vec4 color;

struct Material {
  sampler2D diffuse;
  sampler2D specular;
  float shininess;
};

struct DirectionalLight{
  vec3 direction;
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

struct PointLight{
  vec3 direction;
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float constant;
  float linear;
  float quadratic;
};

#define MAX_DIRECIONAL_LIGHTS 4
#define MAX_POINT_LIGHTS 10

in vec2 v_texCord;
in vec3 v_Normal;
in vec3 v_FragmentPosition;

uniform vec3 u_CameraPosition;
uniform Material u_Material;
uniform DirectionalLight u_DirectionalLights[MAX_DIRECIONAL_LIGHTS];
uniform PointLight u_PointLights[MAX_POINT_LIGHTS];
uniform uint u_nDirectionalLights;
uniform uint u_nPointLights;

vec3 CalcDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDirection);

void main(){

    vec4 materialDiffuse = texture(u_Material.diffuse,v_texCord);
    vec4 materialSpecular = texture(u_Material.specular,v_texCord);
    
    vec3 viewDirection = normalize(u_CameraPosition - v_FragmentPosition);
    vec3 result = vec3(0,0,0);
    
    for(uint i = 0 ; i < u_nDirectionalLights ; i++ ) {
      result += CalcDirectionalLight(u_DirectionalLights[i],v_Normal,viewDirection);
    }
    for(uint i = 0 ; i < u_nPointLights ; i++ ) {
      result += CalcPointLight(u_DirectionalLights[i],v_Normal,v_FragmentPosition,viewDirection);
    }

    color=result;
}
