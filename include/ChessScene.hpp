/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#ifndef _CHESSSCENE_H_
#define _CHESSSCENE_H_

#include "App.hpp"
#include "Helper.hpp"
#include "Macro.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace scene {
  
  class ChessScene : public app::App {
  private:
    gl_utility::Mesh pyramide = gl_utility::Mesh( {
        { glm::vec3(-1,-0.5,0), glm::vec4(1,0,0,1) },               
        { glm::vec3(0,1,0), glm::vec4(0,1,0,1) }, 
        { glm::vec3(1,-0.5,0),  glm::vec4(0,0,1,1) },
        { glm::vec3(0,0,1),  glm::vec4(1,1,1,1) } 
      },  { 
        3,0,1,3,1,2,3,2,0,0,2,1});
    GLuint __modelID;
    GLuint __viewID;
    GLuint __projectionID;
    camera::Camera __camera;
    shader::Shader __shader = initShader();
    shader::Shader initShader();
  public:
    ChessScene();
    void init ();
    void onDraw() override;
    void onMouseMove(double x, double y) override;
    void onMouseDown(int button, int action) override;
    void onMouseScroll(double x, double y) override;
    void onKeyDown(int key, int action) override;
  };
  
}
#endif /* _CHESSSCENE_H_ */
