/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

#include "Mesh.hpp"

gl_utility::Mesh::Mesh(std::vector<helper::Vertex> vertices, std::vector<unsigned int> indices){
  __vertices = vertices;
  __indices = indices;
  
  initMesh();
  
}

gl_utility::Mesh::Mesh(){
}

gl_utility::Mesh::~Mesh(){
  glDeleteBuffers(1, &__vboID);
	glDeleteVertexArrays(1, &__vaoID);
}

void gl_utility::Mesh::initMesh() {
  // gen buffers & array
  glGenVertexArrays(1, &__vaoID);
  glGenBuffers(1, &__vboID);
  glGenBuffers(1, &__vbeID);
  // bind buffers & array
  glBindVertexArray(__vaoID);
  glBindBuffer( GL_ARRAY_BUFFER, __vboID);
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, __vbeID);

  glBufferData(GL_ARRAY_BUFFER, __vertices.size() * sizeof(helper::Vertex), &__vertices[0], GL_STATIC_DRAW);  
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, __indices.size() * sizeof(unsigned int), &__indices[0], GL_STATIC_DRAW);

  // vertex positions
  GLuint positionID = 0;
  GLuint colorID = 1;
  glEnableVertexAttribArray(positionID);
  glEnableVertexAttribArray(colorID);
  
  glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(helper::Vertex), (void*)0);
  glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(helper::Vertex), (void*)offsetof(helper::Vertex, color));
  glBindVertexArray(0);
  glBindBuffer( GL_ARRAY_BUFFER, 0);
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0); 
}


void gl_utility::Mesh::draw(shader::Shader &shader){
  glBindVertexArray(__vaoID);
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, __vbeID);
  glDrawElements(GL_TRIANGLES, __indices.size(), GL_UNSIGNED_INT, 0);
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
} 

