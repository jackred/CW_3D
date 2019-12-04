/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#include "ChessScene.hpp"

scene::ChessScene::ChessScene() : App(900,800, "Chess Scene") {
  init();
}

void scene::ChessScene::init() {
  
  //Specify the 3 VERTICES of A Triangle
  helper::Vertex triangle[] =
    {
     { glm::vec2(-1,0), glm::vec4(1,0,0,1) },               
     { glm::vec2(0,1),  glm::vec4(0,1,0,1) }, 
     { glm::vec2(1,0),  glm::vec4(0,0,1,1) } 
    };
   

  __positionID = glGetAttribLocation(__test.getID(), "position"); // position in shader
  __colorID = glGetAttribLocation(__test.getID(), "color");
  __modelID = glGetUniformLocation(__test.getID(), "model");
  __viewID = glGetUniformLocation(__test.getID(), "view");
  __projectionID = glGetUniformLocation(__test.getID(), "projection");

  __test.unbind();
    
  glGenVertexArrays(1, &__arrayID);
  glBindVertexArray(__arrayID);

  // Generate one buffer
  glGenBuffers(1, &__bufferID);
  // Bind Array Buffer 
  glBindBuffer( GL_ARRAY_BUFFER, __bufferID);
  // Send data over buffer to GPU
  glBufferData( GL_ARRAY_BUFFER, 3 * sizeof(helper::Vertex), triangle, GL_STATIC_DRAW );
    
  glEnableVertexAttribArray(__positionID);
  glEnableVertexAttribArray(__colorID);

  glVertexAttribPointer( __positionID, 2, GL_FLOAT, GL_FALSE, sizeof(helper::Vertex), 0 );
  glVertexAttribPointer(__colorID,4,GL_FLOAT,GL_FALSE,sizeof(helper::Vertex),(void*)sizeof(glm::vec2));

  glBindVertexArray(0);
  glBindBuffer( GL_ARRAY_BUFFER, 0);
}

void scene::ChessScene::onDraw(){
  static float time = 0.0;
  time += .01;
    
  __test.bind();
  glBindVertexArray(__arrayID);

  glm::vec3 eyepos = __camera.getCamPos();
      
  glm::mat4 view = __camera.getLookAtMatrix();
      
  glm::mat4 proj = __camera.getProjectionMatrix(__window);
  
  glUniformMatrix4fv( __viewID, 1, GL_FALSE, glm::value_ptr(view) );
  glUniformMatrix4fv( __projectionID, 1, GL_FALSE, glm::value_ptr(proj) );

  //for (int i = 0; i < 100; ++i){
      
  glm::mat4 translate = glm::translate(glm::mat4(), glm::vec3(0,0,0));
  glm::mat4 rotate = glm::rotate(glm::mat4(), time * PI * 1/100, glm::vec3(0,0,1));
  glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(1.0f- (float)1/100));

  glm::mat4 model = translate * rotate * scale;                        

  glUniformMatrix4fv( __modelID, 1, GL_FALSE, glm::value_ptr(model) );
  glDrawArrays(GL_TRIANGLES, 0, 3);
  //}

  glBindVertexArray(0);
  __test.unbind();
}

void scene::ChessScene::onMouseMove(double x, double y){
  std::cout << x << " " << y << std::endl;
}

void scene::ChessScene::onMouseDown(int button, int action){
  if (action==GLFW_PRESS) {
    std::cout << "mouse pressed" << std::endl;
  }
  if (action==GLFW_RELEASE) {
    std::cout << "mouse released" << std::endl;
  }
}

void scene::ChessScene::onMouseScroll(double x, double y) {
  if (y == 1) {
    __camera.moveForward();
  } else if (y == -1) {
    __camera.moveBackward();
  }
  if (x == 1) {
    __camera.rotateRight();
  } else if (x == -1) {
    __camera.rotateLeft();
  }
  std::cout << __camera.getCamPos()[0]  << " " << __camera.getCamPos()[1] << " " << __camera.getCamPos()[2] << std::endl;
}


void scene::ChessScene::onKeyDown(int key, int action){
  if (key == 262) {
    __camera.moveLeft();
  } else if (key == 263) {
    __camera.moveRight();
  } else if (key == 265) {
    __camera.moveUp();
  } else if (key == 264) {
    __camera.moveDown();
  }
  std::cout << key << std::endl;
}

shader::Shader scene::ChessScene::initShader() {
  std::string vs_path = "../shaders/v_test.glsl";
  std::string fs_path = "../shaders/f_test.glsl";

  return shader::Shader(vs_path, fs_path);
}
  
