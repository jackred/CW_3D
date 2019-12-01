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
#include "Helper.hpp"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace lynda;


struct MyApp : App {
  vector<helper::Vertex> triangle; 

  shader::Shader test = initShader();
  GLuint positionID;
  GLuint colorID;
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
    helper::Vertex v1 = { glm::vec2(-1,-.5), glm::vec4(1,0,0,1) };
    helper::Vertex v2 = { glm::vec2(0,1),    glm::vec4(0,1,0,1) };
    helper::Vertex v3 = { glm::vec2(1,-.5),  glm::vec4(0,0,1,1) };
    triangle.push_back(v1);               
    triangle.push_back(v2); 
    triangle.push_back(v3); 
   

    positionID = glGetAttribLocation(test.getID(), "position"); // position in shader
    colorID = glGetAttribLocation(test.getID(), "color");
    test.unbind();
    
    glGenVertexArrays(1, &arrayID);
    glBindVertexArray(arrayID);

    // Generate one buffer
    glGenBuffers(1, &bufferID);
    // Bind Array Buffer 
    glBindBuffer( GL_ARRAY_BUFFER, bufferID);
    // Send data over buffer to GPU
    glBufferData( GL_ARRAY_BUFFER, triangle.size() * sizeof(helper::Vertex), &(triangle[0]), GL_STATIC_DRAW );
    
    glEnableVertexAttribArray(positionID);
    glEnableVertexAttribArray(colorID);

    glVertexAttribPointer( positionID, 2, GL_FLOAT, GL_FALSE, sizeof(helper::Vertex), 0 );
    glVertexAttribPointer(colorID,4,GL_FLOAT,GL_FALSE,sizeof(helper::Vertex),(void*)sizeof(glm::vec2));

    glBindVertexArray(0);
    glBindBuffer( GL_ARRAY_BUFFER, 0);
  }

  
  virtual void onDraw(){
    test.bind();
    glBindVertexArray(arrayID);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    test.unbind();
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
