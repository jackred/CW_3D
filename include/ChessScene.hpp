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
#include "Tile.hpp"
#include "Model.hpp"
#include "KvsD.hpp"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

namespace scene {
  
  class ChessScene : public app::App {
  private:
    gl_utility::Mesh blackTile = gl_utility::Mesh(object::getTileOfColor(glm::vec4(0,0,0,1)), object::getindicesTile());
    gl_utility::Mesh whiteTile = gl_utility::Mesh(object::getTileOfColor(glm::vec4(1,1,1,1)), object::getindicesTile());
    gl_utility::Mesh pyramide = gl_utility::Mesh(object::getPyramide(), object::getIndicesPyramide());
    scene::Model wKing = scene::Model("../object/king.obj", glm::vec4(0,0,1,1));
    scene::Model wQueen = scene::Model("../object/queen.obj", glm::vec4(0,0,0.9,1));
    scene::Model wRock = scene::Model("../object/rock.obj", glm::vec4(0,0,0.8,1));
    scene::Model wPawn = scene::Model("../object/pawn.obj", glm::vec4(0,0,0.7,1));
    scene::Model wBishop = scene::Model("../object/bishop.obj", glm::vec4(0,0,0.6,1));

    scene::Model bKing = scene::Model("../object/king.obj", glm::vec4(1,0,0,1));
    scene::Model bQueen = scene::Model("../object/queen.obj", glm::vec4(0.9,0,0,1));
    scene::Model bRock = scene::Model("../object/rock.obj", glm::vec4(0.8,0,0,1));
    scene::Model bPawn = scene::Model("../object/pawn.obj", glm::vec4(0.7,0,0,1));
    scene::Model bBishop = scene::Model("../object/bishop.obj", glm::vec4(0.6,0,0,1));
    const int __minTurn = 1;
    const int __maxTurn = 21;
    int __turn = __minTurn;
    play::Play __play = play::getPlay(__turn);
    
    GLuint __modelID;
    GLuint __viewID;
    GLuint __projectionID;
    camera::Camera __camera;
    shader::Shader __shader = initShader();
    shader::Shader initShader();
    void drawPawns();
    void drawBoard();
    void drawQueens();
    void drawRocks();
    void drawBishops();   
    void drawKings();
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
