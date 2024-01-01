#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCord;
out vec2 v_texCord;
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;
void main(){
   gl_Position = u_Projection * u_Model * u_View * position;
   v_texCord = texCord;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;
in vec2 v_texCord;

void main(){
  vec4 texColor = texture(u_Texture,v_texCord);
   color = texColor;
}


