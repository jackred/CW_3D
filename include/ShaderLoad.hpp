/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#ifndef _SHADERLOAD_H_
#define _SHADERLOAD_H_

#include "gl_lib.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace load {

  class ShaderLoad {
  private:
    std::string __shader;
    void readFile(std::ifstream &file);
  public:
    ShaderLoad(const std::string &file_name);
    //~ShaderLoad();
    const char* getShader() const;
  };
}
#endif /* _SHADERLOAD_H_ */
