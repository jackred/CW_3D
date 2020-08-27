/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
// inspired from fork with Timothée Couble and opengl-tutorial.org

#ifndef _OBJLOADER_H_
#define _OBJLOADER_H_

#include <iostream>
#include <fstream>
//#include <sstream>
#include "Lib.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Helper.hpp"

#include <algorithm>
#include <vector>
#include <string>

namespace object{
  class ObjLoader {
  private:
    std::string __filePath;
    std::vector<helper::Vertex> __vertices;
    std::vector<unsigned int> __indices;
    std::vector<glm::vec3> __position;
    std::vector<glm::vec4> __color;
    void loadFile(std::ifstream &file);
    glm::vec3 getValuesVec3(std::string &str);
    void buildVertices(std::string &str);
    void buildIndices(unsigned int start, unsigned int triangle_nb);
  public:
    ObjLoader(std::string path);
    const ObjLoader &load();
    const std::vector<helper::Vertex>& getVertices() const;
    const std::vector<unsigned int>& getIndices() const;
  };

#endif /* _OBJLOADER_H_ */
}
