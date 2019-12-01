/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#ifndef _SHADER_H_
#define _SHADER_H_

#include "Lib.hpp"
#include "ShaderLoad.hpp"

namespace shader {

  class Shader {
  private:
    GLuint __sID;
    void compilerCheck(GLuint ID);
    void shaderLinkCheck(GLuint ID);
    void buildShader(GLuint ID, const std::string &file_name);
    void compileShader(GLuint ID, const char *shader);
  public:
    Shader(const std::string &vs_file_name, const std::string &fs_file_name);
    void bind();
    void unbind();
    GLuint getID();
    //~Shader();
  };
}
#endif /* _SHADER_H_ */
