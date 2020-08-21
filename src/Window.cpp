/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

#include "Window.hpp"

app::Interface* window::WInterface::app;

window::Window::~Window() {
  glfwDestroyWindow(__window);
}

void window::Window::create(app::Interface* app, int width, int height, const std::string &name){
  __interface.app = app;
  __width = width;
  __height = height;

  __window = glfwCreateWindow(width,height,name.c_str(),NULL ,NULL);
  if (!__window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }        
  glfwMakeContextCurrent(__window);
  glfwSwapInterval(1); //<-- force interval (not guaranteed to work with all graphics drivers)

  //register callbacks for keyboard and mouse
  glfwSetKeyCallback(__window, WInterface::OnKeyDown);
  glfwSetCursorPosCallback(__window, WInterface::OnMouseMove);
  glfwSetMouseButtonCallback(__window, WInterface::OnMouseDown);
  glfwSetScrollCallback(__window, WInterface::OnMouseScroll);

}


void window::Window::setViewport(){ 
  glfwGetFramebufferSize(__window, &__width, &__height); 
  glViewport(0,0,__width,__height);  
}

bool window::Window::shouldClose(){
  return glfwWindowShouldClose(__window);
}

void window::Window::swapBuffers(){
  glfwSwapBuffers(__window);
}

const int window::Window::getWidth()  {
  return __width;
}

const int window::Window::getHeight() {
  return __height;
}

const float window::Window::getRatio() {
  return (float)__width / (float)__height;
}
