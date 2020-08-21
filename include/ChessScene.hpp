/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#ifndef _CHESSSCENE_H_
#define _CHESSSCENE_H_

#include "App.hpp"
#include "Shader.hpp"
#include "Helper.hpp"
#include "Macro.hpp"
#include "Camera.hpp"

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
    shader::Shader __test = initShader();
    GLuint __positionID;
    GLuint __elementID;
    GLuint __colorID;
    GLuint __vaoID;
    GLuint __vboID;
    GLuint __modelID;
    GLuint __viewID;
    GLuint __projectionID;
    float x,y,z = 1;
    shader::Shader initShader();
    camera::Camera __camera;
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
