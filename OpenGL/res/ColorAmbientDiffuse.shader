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
    gl_Position = u_Projection * u_View * u_Model * vec4(aPos, 1.0);
}

#shader fragment
#version 330 core

out vec4 color;

in vec3 v_Normal;
in vec3 v_FragmentPosition;

uniform sampler2D texture_diffuse1;
uniform float u_AmbientStrength;
uniform vec3 u_LightPosition;
uniform vec3 u_LightColor;

in vec2 v_texCord;

void main(){
    vec4 texColor = texture(texture_diffuse1,v_texCord);
    vec3 lightDirection = normalize( u_LightPosition - v_FragmentPosition);
    vec3 diffuse = max(dot(lightDirection,v_Normal),0)* u_LightColor;
    color = (u_AmbientStrength + diffuse) * texColor; 
}
