/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#ifndef _MESH_H_
#define _MESH_H_

#include "Helper.hpp"
#include "Lib.hpp"
#include "Shader.hpp"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <vector>

namespace gl_utility {
  class Mesh {
  private:
    void initMesh();
    shader::Shader initShader();
    GLuint __vaoID;
    GLuint __vboID;
    GLuint __vbeID;
    std::vector<helper::Vertex> __vertices;
    std::vector<unsigned int> __indices;

    
  public:
    Mesh(std::vector<helper::Vertex> vertices,std::vector<unsigned int> indices);
    ~Mesh();
    void draw(shader::Shader &shader);
  };
}
#endif /* _MESH_H_ */

  
