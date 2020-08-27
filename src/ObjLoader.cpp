/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
// inspired from fork with Timothée Couble and opengl-tutorial.org

#include "ObjLoader.hpp"

object::ObjLoader::ObjLoader(std::string path){
  __filePath = path;
  std::ifstream file(__filePath);
  if (file.is_open()) {
    std::cout << "Loading file at __filePath: " << __filePath << std::endl;
    loadFile(file);
    file.close();
  } else
    std::cerr << "File failed to load at __filePath: " << __filePath << std::endl;
}

const object::ObjLoader& object::ObjLoader::load() {
  return *this;
}


void object::ObjLoader::loadFile(std::ifstream &file) {
  std::string line;
  while (std::getline(file, line)) {
    //std::cout << line << std::endl;
    std::string type = line.substr(0, line.find(' '));
    std::string value = line.substr(line.find(' ') + 1, line.size());
    if (type == "v") {
      __position.push_back(getValuesVec3(value));
    }
    if (type == "vt") {
      //_texture.push_back(getValuesVec2(value));
    }
    if (type == "vn") {
      //_normal.push_back(getValuesVec3(value));
    }
    if (type == "f") {
      buildVertices(value);
    }
    
  }
}

void object::ObjLoader::buildVertices(std::string &str) {

  std::string vertex1, vertex2, vertex3;
  unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
  int matches = sscanf(str.c_str(), "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
  if (matches != 9){
    printf("File can't be read by our simple parser : ( Try exporting with other options\n");
    return;
  }
  std::vector<helper::Vertex> list;
  for (int i = 0; i < 3; i++) {
    helper::Vertex vertex = {};
    vertex.position = __position[vertexIndex[i]];
    vertex.color = glm::vec4(0,0,1,1);
    list.push_back(vertex);
  }
  buildIndices((unsigned int) __vertices.size(), 1);
  __vertices.insert(__vertices.end(), list.begin(), list.end());
  
  
  // std::vector<helper::Vertex> list;
  // int index[3] = {};

  // unsigned int spaces = (unsigned int) std::count(str.begin(), str.end(), ' ');
  // unsigned int del = (unsigned int) std::count(str.begin(), str.end(), '/');
  // if (spaces < 2 || del / (spaces + 1) != 2) {
  //   std::cerr << "Wrong format line: \"" << str << "\" from: " << __filePath << std::endl;
  //   return;
  // }
  // std::cout << spaces << std::endl;
  // std::cout << del << std::endl;
  // for (unsigned int i = 0; i < spaces + 1; i++) {
  //   size_t posI = str.find(' ');
  //   std::string token = str.substr(0, posI);
  //   str.erase(0, posI + 1);
  //   for (unsigned int j : {0, 1, 2}) {
  //     size_t posJ = token.find('/');
  //     index[j] = std::stoi(token.substr(0, posJ)) - 1;
  //     token.erase(0, posJ + 1);
  //   }
  //   helper::Vertex vertex = {};
  //   vertex.position = __position[index[0]];
  //   vertex.color = glm::vec4(0,0,1,1);
  //   list.push_back(vertex);
  // }
  // buildIndices((unsigned int) __vertices.size(), spaces - 1);
  // __vertices.insert(__vertices.end(), list.begin(), list.end());
}

void object::ObjLoader::buildIndices(unsigned int start, unsigned int triangle_nb) {
  for (unsigned int i = 0; i < triangle_nb; i++) {
    __indices.push_back(start);
    __indices.push_back(start + i + 1);
    __indices.push_back(start + i + 2);

   __indices.push_back(start);
    __indices.push_back(start + i + 2);
    __indices.push_back(start + i + 1);
    
    __indices.push_back(start + i + 1);
    __indices.push_back(start);
    __indices.push_back(start + i + 2);
    
    __indices.push_back(start + i + 1);
    __indices.push_back(start + i + 2);
    __indices.push_back(start);

    __indices.push_back(start + i + 2);
    __indices.push_back(start + i + 1);
    __indices.push_back(start);
    
    __indices.push_back(start + i + 2);
    __indices.push_back(start);
    __indices.push_back(start + i + 1);
  }
}

const std::vector<helper::Vertex>& object::ObjLoader::getVertices() const{
  return __vertices;
}

const std::vector<unsigned int>& object::ObjLoader::getIndices() const{
  return __indices;
}

glm::vec3 object::ObjLoader::getValuesVec3(std::string &str) {
  char *end;
  glm::vec3 values;

  size_t spaces = std::count(str.begin(), str.end(), ' ');
  if (spaces != 2)
    std::cerr << "Wrong format line: \"" << str << "\" from: " << __filePath << std::endl;

  for (unsigned int i = 0; i < 3; i++) {
    values[i] = std::strtof(str.c_str(), &end);
    str = std::string(end);
  }
  return values;
}
