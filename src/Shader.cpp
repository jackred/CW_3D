/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#include "Shader.hpp"

shader::Shader::Shader(const std::string &vs_file_name, const std::string &fs_file_name){
  __sID = glCreateProgram();
  GLuint vID = glCreateShader(GL_VERTEX_SHADER);
  GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);
  buildShader(vID, vs_file_name);
  buildShader(fID, fs_file_name);
  glLinkProgram(__sID);
  shaderLinkCheck(__sID);
  bind();
  glDeleteShader(vID);
  glDeleteShader(fID);
}

void shader::Shader::buildShader(GLuint ID, const std::string &file_name) {
  load::ShaderLoad loader = load::ShaderLoad(file_name);
  const char* source = loader.getShader();
  compileShader(ID, source);
}

void shader::Shader::compileShader(GLuint ID, const char *shader) {
  glShaderSource(ID, 1, &shader, NULL);
  glCompileShader(ID);
  compilerCheck(ID);
  glAttachShader(__sID, ID);
}

void shader::Shader::compilerCheck(GLuint ID) {
  GLint comp;
  glGetShaderiv(ID, GL_COMPILE_STATUS, &comp);
  if (comp == GL_FALSE) {
    std::cerr << "Shader Compilation FAILED" << std::endl;
    GLchar messages[256];
    glGetShaderInfoLog(ID, sizeof(messages),0,&messages[0]);
    std::cerr << messages;
  }
}

void shader::Shader::shaderLinkCheck(GLuint ID){
  GLint linkStatus, validateStatus;
  glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);
			

  if(linkStatus == GL_FALSE ){
    std::cerr << "Shader Linking FAILED" << std::endl;
    GLchar messages[256];
    glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
    std::cerr << messages;
  }

  glValidateProgram(ID);
  glGetProgramiv(ID, GL_VALIDATE_STATUS, &validateStatus);
  	
  if(linkStatus == GL_FALSE ){
    std::cerr << "Shader Validation FAILED" << std::endl;
    GLchar messages[256];
    glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
    std::cerr << messages;
  }
}

void shader::Shader::bind() {
  glUseProgram(__sID);
}

void shader::Shader::unbind() {
  glUseProgram(0);
}

GLuint shader::Shader::getID() {
  return __sID;
}
