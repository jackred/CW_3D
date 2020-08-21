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
      { glm::vec3(-1,-0.5,0), glm::vec4(1,0,0,1) },               
      { glm::vec3(0,1,0), glm::vec4(0,1,0,1) }, 
      { glm::vec3(1,-0.5,0),  glm::vec4(0,0,1,1) },
      { glm::vec3(0,0,1),  glm::vec4(1,1,1,1) } 
    };
  
  GLubyte indices[12] = { 
    3,0,1,3,1,2,3,2,0,0,2,1}; //bottom


  __positionID = glGetAttribLocation(__test.getID(), "position"); // position in shader
  __colorID = glGetAttribLocation(__test.getID(), "color");
  __modelID = glGetUniformLocation(__test.getID(), "model");
  __viewID = glGetUniformLocation(__test.getID(), "view");
  __projectionID = glGetUniformLocation(__test.getID(), "projection");

  __test.unbind();
    
  glGenVertexArrays(1, &__vaoID);
  glBindVertexArray(__vaoID);

  // Generate one buffer
  glGenBuffers(1, &__vboID);
  // Bind Array Buffer 
  glBindBuffer( GL_ARRAY_BUFFER, __vboID);
  // Send data over buffer to GPU
  glBufferData( GL_ARRAY_BUFFER, 4 * sizeof(helper::Vertex), triangle, GL_STATIC_DRAW );
    

  glGenBuffers(1, &__elementID);
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, __elementID);
  glBufferData( GL_ELEMENT_ARRAY_BUFFER, 12 * sizeof(GLubyte), indices, GL_STATIC_DRAW );


  
  glEnableVertexAttribArray(__positionID);
  glEnableVertexAttribArray(__colorID);

  glVertexAttribPointer( __positionID, 3, GL_FLOAT, GL_FALSE, sizeof(helper::Vertex), 0 );
  glVertexAttribPointer(__colorID,4,GL_FLOAT,GL_FALSE,sizeof(helper::Vertex),(void*)sizeof(glm::vec3));

  glBindVertexArray(0);
  glBindBuffer( GL_ARRAY_BUFFER, 0);
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0); 

}

void scene::ChessScene::onDraw(){
  static float time = 0.0;
  time += .01;
    
  __test.bind();
  glBindVertexArray(__vaoID);

      
  glm::mat4 view = __camera.getLookAtMatrix();
      
  glm::mat4 proj = __camera.getProjectionMatrix(__window);
  
  glUniformMatrix4fv( __viewID, 1, GL_FALSE, glm::value_ptr(view) );
  glUniformMatrix4fv( __projectionID, 1, GL_FALSE, glm::value_ptr(proj) );
      
  glm::mat4 translate = glm::translate(glm::mat4(), glm::vec3(0,0,0));
  glm::mat4 rotate = glm::rotate(glm::mat4(), 0.0f, glm::vec3(0,0,1));
  glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(1.0f));

  glm::mat4 model = translate * rotate * scale;                        

  glUniformMatrix4fv( __modelID, 1, GL_FALSE, glm::value_ptr(model) );
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, __elementID);
  glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, 0);
  //}

  glBindVertexArray(0);
  __test.unbind();



  // std::cout << __camera.getCamPos()[0]  << " " << __camera.getCamPos()[1] << " " << __camera.getCamPos()[2] << " | " << __camera.getRadius() << std::endl;

  
}

void scene::ChessScene::onMouseMove(double x, double y){
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
    std::cout << "1 -> forward" << std::endl;
    __camera.moveForward();
  } else if (y == -1) {
    std::cout << "-1 -> backward  " << std::endl;
    __camera.moveBackward();
  }
  std::cout << __camera.getCamPos()[0]  << " " << __camera.getCamPos()[1] << " " << __camera.getCamPos()[2] << std::endl;
}


void scene::ChessScene::onKeyDown(int key, int action){
  if (key == 262) {
    __camera.moveLeft();
  } else if (key == 263) {
    __camera.moveRight();
  } else if (key == 265) {
  } else if (key == 264) {
  }
  std::cout << __camera.getCamPos()[0]  << " " << __camera.getCamPos()[1] << " " << __camera.getCamPos()[2] << std::endl;

  std::cout << key << std::endl;
}

shader::Shader scene::ChessScene::initShader() {
  std::string vs_path = "../shaders/v_test.glsl";
  std::string fs_path = "../shaders/f_test.glsl";
  return shader::Shader(vs_path, fs_path);
}
  
