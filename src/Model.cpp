/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
// inspired from fork with Timothée Couble and opengl-tutorial.org

#include "Model.hpp"

scene::Model::Model(std::string path, glm::vec4 color){
  __color = color;
  loadModel(path);
}

void scene::Model::draw(shader::Shader &shader) {
  __mesh->draw(shader);
}

void scene::Model::loadModel(std::string path) {
  auto objModel = object::ObjLoader(path).load();
  std::vector<helper::Vertex> vertices = objModel.getVertices();
  for (int i = 0; i < vertices.size(); i++) {
    vertices[i].color = __color;
  }
  __mesh = new gl_utility::Mesh(vertices, objModel.getIndices());
}

// void scene::Model::setPosition(glm::vec3 position) {
//   __position = position;
// }

// void scene::Model::setOrientation(glm::vec3 orientation) {
//   __orientation = orientation;
// }

// void scene::Model::setSize(glm::vec3 size) {
//   _size = size;
// }
