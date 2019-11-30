/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

/*
  references and code are used from:
  https://www.linkedin.com/learning/learning-opengl/
  by Pablo Colapinto (), gmail -> wolftype
*/

#include "App.hpp"
#include "Shader.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#ifndef GLSL 
#define GLSL(version,A) "#version " #version "\n" #A
#endif
using namespace lynda;


struct MyApp : App {
  vector<glm::vec2> triangle; 

  shader::Shader test = initShader();
  GLuint positionID;
  //A buffer ID
  GLuint bufferID;
  //A Vertex Array ID
  GLuint arrayID;


  MyApp() : App() { init(); }

  shader::Shader initShader() {
    std::string vs_path = "../shaders/v_test.glsl";
    std::string fs_path = "../shaders/f_test.glsl";

    return shader::Shader(vs_path, fs_path);
  }
  
  void init() {
    
    //Specify the 3 VERTICES of A Triangle
    triangle.push_back( glm::vec2(-1,-.5) );               
    triangle.push_back( glm::vec2(0,1) ); 
    triangle.push_back( glm::vec2(1,-.5) );

   

    positionID = glGetAttribLocation(test.getID(), "position"); // position in shader

    test.stopUseShader();
    
    glGenVertexArrays(1, &arrayID);
    glBindVertexArray(arrayID);

    // Generate one buffer
    glGenBuffers(1, &bufferID);
    // Bind Array Buffer 
    glBindBuffer( GL_ARRAY_BUFFER, bufferID);
    // Send data over buffer to GPU
    glBufferData( GL_ARRAY_BUFFER, triangle.size() * sizeof(glm::vec2), triangle.data(), GL_STATIC_DRAW );
    
    glEnableVertexAttribArray(positionID);

    glVertexAttribPointer( positionID, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), 0 );
    glBindVertexArray(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);
  }

  
  virtual void onDraw(){
    test.useShader();
    glBindVertexArray(arrayID);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    test.stopUseShader();
  }
    
  virtual void onMouseMove(int x, int y){
    cout << x << " " << y << endl;
  }
  virtual void onMouseDown(int button, int action){
    if (action==GLFW_PRESS) cout << "mouse pressed" <<endl;
    if (action==GLFW_RELEASE) cout << "mouse released" <<endl;
  }
  virtual void onKeyDown(int key, int action){
    cout << (unsigned char)key << endl;
  }
};


int main(int argc, const char ** argv){
  MyApp app;
  app.start();
  
  printf("goodbye window\n");

  return 0;
}
