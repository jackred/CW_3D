/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

#include "Model.hpp"

scene::Model::Model(std::string path, glm::vec4 color){
  __color = color;
  loadModel(path);
}

void scene::Model::draw(shader::Shader &shader) {
  __mesh.draw(shader);
}

void scene::Model::loadModel(std::string path) {
  auto objModel = object::ObjLoader(path).load();
  std::vector<helper::Vertex> vertices = objModel.getVertices();
  std::cout << "size:" << vertices.size() << std::endl;
  for (int i = 0; i < vertices.size(); i++) {
    vertices[i].color = __color;
    std::cout << vertices[i].position[0] << " " << vertices[i].position[1] << " " <<  vertices[i].position[2] << " | " << vertices[i].color[0] << " " << vertices[i].color[1] << " " << vertices[i].color[2] << " " << vertices[i].color[3] <<  std::endl;
  }
  std::vector<unsigned int> tmp = objModel.getIndices();
  // for (int i = 0; i <3; i++) {
  //   std::cout << vertices[i].position[0] << " " << vertices[i].position[1] << " " <<  vertices[i].position[2] << " | " << vertices[i].color[0] << " " << vertices[i].color[1] << " " << vertices[i].color[2] << " " << vertices[i].color[3] <<  std::endl;
  // }
  std::cout << "size indice" << tmp.size() << std::endl;
  for (int i = 0 ; i < tmp.size(); i+=3) {
    std::cout << tmp[i] << " " << tmp[i+1] <<" " << tmp[i+2] << std::endl;
  }
  __mesh = gl_utility::Mesh(vertices, objModel.getIndices());
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
