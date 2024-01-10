#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec2 v_texCord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    v_texCord = aTexCoords;    
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
#shader fragment
#version 330 core

out vec4 color;

in vec2 v_texCord;

void main(){
   color = vec4(1.0f,1.0f,1.0f,1.0f);
}

