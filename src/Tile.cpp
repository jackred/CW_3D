/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */


#include "Tile.hpp"

std::vector<helper::Vertex> object::getTileOfColor(glm::vec4 color){
  return  {
    {glm::vec3(0.0f, 0.0f, -0.0f), color}, // back
    {glm::vec3(1.0f, 0.0f, -0.0f),  color},
    {glm::vec3(1.0f, 1.0f, -0.0f),   color},
    {glm::vec3(0.0f, 1.0f, -0.0f),  color},

    {glm::vec3(0.0f, 0.0f, 1.0f),  color}, // front
    {glm::vec3(1.0f, 0.0f, 1.0f),   color},
    {glm::vec3(1.0f, 1.0f, 1.0f),    color},
    {glm::vec3(0.0f, 1.0f, 1.0f),   color},

    {glm::vec3(0.0f, 1.0f, 1.0f),   color}, // left
    {glm::vec3(0.0f, 1.0f, -0.0f),  color},
    {glm::vec3(0.0f, 0.0f, -0.0f), color},
    {glm::vec3(0.0f, 0.0f, 1.0f),  color},

    {glm::vec3(1.0f,  1.0f,  1.0f),   color}, // right
    {glm::vec3(1.0f,  1.0f, -0.0f),   color},
    {glm::vec3(1.0f, 0.0f, -0.0f),   color},
    {glm::vec3(1.0f, 0.0f,  1.0f),   color},

    {glm::vec3(0.0f, 0.0f, -0.0f),  color}, // bottom
    {glm::vec3(1.0f, 0.0f, -0.0f),   color},
    {glm::vec3(1.0f, 0.0f,  1.0f),   color},
    {glm::vec3(0.0f, 0.0f,  1.0f),  color},

    {glm::vec3(0.0f,  1.0f, -0.0f),  color}, // top
    {glm::vec3(1.0f,  1.0f, -0.0f),   color},
    {glm::vec3(1.0f,  1.0f,  1.0f),   color},
    {glm::vec3(0.0f,  1.0f,  1.0f),  color}
  };
}

std::vector<unsigned int> object::getindicesTile() {
  return {
    0, 2, 1, //back
    0, 3, 2,
    4, 6, 5, //front
    4, 7, 6,
    8, 9, 10, // left
    8, 10, 11,
    12, 14, 13, // right
    12, 15, 14,
    16, 17, 18, // bottom
    16, 18, 19,
    20, 22, 21, //top
    20, 23, 22
  };
}

std::vector<helper::Vertex> object::getPyramide(){
  return {
    { glm::vec3(-1,-0.5,0),  glm::vec4(0,1,0,1)},               
    { glm::vec3(0,1,0), glm::vec4(1,0,0,1) }, 
    { glm::vec3(1,-0.5,0),  glm::vec4(0,0,1,1) },
    { glm::vec3(0,0,1),  glm::vec4(1,1,1,1) } 
  }; 
}

std::vector<unsigned int> object::getIndicesPyramide(){
  return {3,0,1,3,1,2,3,2,0,0,2,1};
};
