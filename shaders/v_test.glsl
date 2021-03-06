#version 120
  
attribute vec4 position;
attribute vec4 color;

varying vec4 dstColor;

uniform mat4 model;
uniform mat4 view;                                      //<-- 4x4 Transformation Matrices
uniform mat4 projection;

void main(){
  dstColor = color;
  gl_Position = projection * view * model * position;   //<-- Apply transformation 
}
