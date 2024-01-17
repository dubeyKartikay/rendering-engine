#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec2 v_texCord;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    v_texCord = aTexCoords;    
    gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0);
}
#shader fragment
#version 330 core

out vec4 color;

uniform sampler2D texture_diffuse1;
uniform float ambientStrength;
uniform vec3 lightColor;

in vec2 v_texCord;

void main(){
    vec4 texColor = texture(texture_diffuse1,v_texCord);
    textColor = ambientStrength * vec4(lightColor,1.0f) * textColor;
    color = texColor;
}
