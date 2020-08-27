/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
// inspired from fork with Timothée Couble and opengl-tutorial.org

#ifndef _MODEL_H_
#define _MODEL_H_

#include "Lib.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "ObjLoader.hpp"

#include <iostream>
#include <vector>
#include <string>

namespace scene{
  class Model {
    glm::vec4 __color;
    glm::vec3 __position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 __orientation = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 __size = glm::vec3(1.0f, 1.0f, 1.0f);
    void loadModel(std::string path);

  public:
    Model(std::string path, glm::vec4 color);
    void draw(shader::Shader &shader);
    
  private:
    gl_utility::Mesh* __mesh;
  };

#endif /* _MODEL_H_ */

}
