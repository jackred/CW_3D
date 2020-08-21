/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#include "ShaderLoad.hpp"

load::ShaderLoad::ShaderLoad(const std::string &file_name){
  std::ifstream file(file_name);
  if (file.is_open()) {
    std::cout << "Reading " << file_name << std::endl;
    readFile(file);
    file.close();
  } else {
    std::cerr << "Error, can't read " << file_name << std::endl;
  }
}

void load::ShaderLoad::readFile(std::ifstream &file) {
  std::string shader_line;
  if (file.is_open()) {
    while (getline(file, shader_line)) {
      __shader += shader_line;
      __shader += '\n';
    }
  }
}

const char *load::ShaderLoad::getShader() const{
  return __shader.c_str();
}
