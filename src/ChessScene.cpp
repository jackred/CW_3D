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

  __modelID = glGetUniformLocation(__shader.getID(), "model");
  __viewID = glGetUniformLocation(__shader.getID(), "view");
  __projectionID = glGetUniformLocation(__shader.getID(), "projection");

  __shader.unbind();

}

void scene::ChessScene::onDraw(){
  static float time = 0.0;
  time += .01;
  __shader.bind();

      
  glm::mat4 view = __camera.getLookAtMatrix();
      
  glm::mat4 proj = __camera.getProjectionMatrix(__window);
  
  glUniformMatrix4fv( __viewID, 1, GL_FALSE, glm::value_ptr(view) );
  glUniformMatrix4fv( __projectionID, 1, GL_FALSE, glm::value_ptr(proj) );
      
  glm::mat4 rotate = glm::rotate(glm::mat4(), 0.0f, glm::vec3(0,0,1));
  glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(1.0f));
  glm::mat4 translate = glm::translate(glm::mat4(), glm::vec3(0,0,0));
  glm::mat4 model = translate * rotate * scale;
  glUniformMatrix4fv( __modelID, 1, GL_FALSE, glm::value_ptr(model) );
  // king.draw(__shader);
  // block.draw(__shader);
  // bloc.draw(__shader);
  // queen.draw(__shader);
  // rock.draw(__shader);
  cube.draw(__shader);
  // blackTile.draw(__shader);
  // pyramide.draw(__shader);
  // pyramide.draw(__shader);
  // int i;
  // int j;
  // for (i = 0; i < 8; i++) {
  //   for (j = 0; j < 8; j++) {
  //     translate = glm::translate(glm::mat4(), glm::vec3(i,j,0));
  //     model = translate * rotate * scale;                        
  //     glUniformMatrix4fv( __modelID, 1, GL_FALSE, glm::value_ptr(model) );
  //     if ((i+j) % 2 == 0) {
  //       blackTile.draw(__shader);
  //     } else {
  //       whiteTile.draw(__shader);     
  //     }
  //   }
  // }

  __shader.unbind();

  int x;
  //std::cin >> x; 

  //std::cout << __camera.getCamPos()[0]  << " " << __camera.getCamPos()[1] << " " << __camera.getCamPos()[2] << " | " << __camera.getRadius() << std::endl;

  
}

void scene::ChessScene::onMouseMove(double x, double y){
}

void scene::ChessScene::onMouseDown(int button, int action){
  // if (action==GLFW_PRESS) {
  //   std::cout << "mouse pressed" << std::endl;
  // }
  // if (action==GLFW_RELEASE) {
  //   std::cout << "mouse released" << std::endl;
  // }
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
