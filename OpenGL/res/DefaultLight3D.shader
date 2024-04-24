#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec2 v_texCord;
out vec3 v_Normal;
out vec3 v_FragmentPosition;
out vec3 v_CameraPosition;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;
uniform vec3 u_CameraPosition;

void main()
{
    v_texCord = aTexCoords;    
    v_FragmentPosition = vec3(u_Model* vec4(aPos,1.0f));
    v_CameraPosition = vec3(u_Model* vec4(u_CameraPosition,1.0f));
    v_Normal = mat3(transpose(inverse(u_Model))) * normalize(aNormal);
    gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core

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
  vec3 position;
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float constant;
  float linear;
  float quadratic;
};

#define MAX_DIRECIONAL_LIGHTS 4
#define MAX_POINT_LIGHTS 10

out vec4 color;
in vec2 v_texCord;
in vec3 v_Normal;
in vec3 v_FragmentPosition;
in vec3 v_CameraPosition;
uniform Material u_Material;
uniform DirectionalLight u_DirectionalLights[MAX_DIRECIONAL_LIGHTS];
uniform PointLight u_PointLights[MAX_POINT_LIGHTS];
//uniform uint u_nPointLights;

vec3 CalcDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDirection);

void main(){

    vec4 materialDiffuse = texture(u_Material.diffuse,v_texCord);
    vec4 materialSpecular = texture(u_Material.specular,v_texCord);
    
    vec3 viewDirection = normalize(v_CameraPosition - v_FragmentPosition);
   vec3 result = vec3(0,0,0);
  
//    for(int i = 0 ; i < MAX_DIRECIONAL_LIGHTS ; i++ ) {
  //    result += CalcDirectionalLight(u_DirectionalLights[i],v_Normal,viewDirection);
 //   }
    for(int i = 0 ; i < MAX_POINT_LIGHTS ; i++ ) {
      result +=  CalcPointLight(u_PointLights[i],v_Normal,v_FragmentPosition,viewDirection);
    }

    color= vec4(abs(v_Normal),1);  
}

vec3 CalcDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection){
  vec3 lightDirection = normalize(-light.direction);
  float diff = max(dot(normal,lightDirection),0);
  float spec = pow(max(dot(normal, normalize(viewDirection + lightDirection)),0),u_Material.shininess);
  vec3 materialDiffuse = vec3(texture(u_Material.diffuse,v_texCord));
  vec3 materialSpecular = vec3(texture(u_Material.specular,v_texCord));
  vec3 ambient = light.ambient * materialDiffuse;
  vec3 diffuse = light.diffuse * diff * materialDiffuse;
  vec3 specular = light.specular * spec *materialSpecular;
  return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDirection){
  vec3 lightDirection = normalize(light.position - v_FragmentPosition);
  float diff = max(dot(normal,lightDirection),0);
  float spec = pow(max(dot(normal, normalize(viewDirection + lightDirection)),-1),u_Material.shininess);

  float distance =  length(light.position - v_FragmentPosition);
  float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

  vec3 materialDiffuse = vec3(texture(u_Material.diffuse,v_texCord));
  vec3 materialSpecular = vec3(texture(u_Material.specular,v_texCord));

  vec3 ambient = light.ambient * materialDiffuse;
  vec3 diffuse = light.diffuse * diff * materialDiffuse;
  vec3 specular = light.specular * spec *materialSpecular;
  return (ambient + diffuse + specular)*attenuation;


}
