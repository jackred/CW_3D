/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#include "App.hpp"

app::App::App(int width, int height, const std::string &name){
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
  std::cout << "glfw initialized \n" << std::endl;

  hintsGLFW();

  __window.create(this, width, height, name);
  std::cout << "window created" << std::endl;
  
  glewExperimental = GL_TRUE;
  GLenum errGLEW = glewInit();
  if (GLEW_OK != errGLEW) {
    std::cout << "Could not initialise GLEW..." << std::endl << glewGetErrorString(errGLEW) << std::endl;
  }
  if (GLEW_APPLE_vertex_array_object){
    printf("genVertexArrayAPPLE supported\n");
  } else if (GLEW_ARB_vertex_array_object){
    printf("genVertexArrays supported\n");
  }

  glFrontFace(GL_CCW);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS); // glDepthFunc(GL_LEQUAL); 
        
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

app::App::~App() {
  glfwTerminate();
}

window::Window& app::App::getWindow() {
  return __window;
}

void app::App::start() {
  std::cout << "Start app ..." << std::endl;
  while (!__window.shouldClose()){
    __window.setViewport();
 
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    onDraw();
        
    __window.swapBuffers();
    glfwPollEvents();
  }
}

void app::App::onDraw() {}
void app::App::onMouseMove(double x, double y) {}
void app::App::onMouseDown(int button, int action) {}
void app::App::onMouseScroll(double x, double y) {}
void app::App::onKeyDown(int key, int action) {}


void app::App::hintsGLFW() {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
