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


#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "Lib.hpp"
#include "Interface.hpp"
#include <iostream>


namespace window{


  struct WInterface {
    static app::Interface * app; // <-- an unknown application to be defined later

    static void OnKeyDown(GLFWwindow* window, int key, int scancode, int action, int mods){
      app->onKeyDown(key,action);
    }

    static void OnMouseMove(GLFWwindow* window, double x, double y){
      app->onMouseMove(x,y);  
    }

    static void OnMouseDown(GLFWwindow* window, int button, int action, int mods){
      app->onMouseDown(button,action);
    }
    
    static void OnMouseScroll(GLFWwindow* window, double x, double y) {
      app->onMouseScroll(x, y);
    }
  };


  /*-----------------------------------------------------------------------------
   *  A GLFW Window Wrapper
   *-----------------------------------------------------------------------------*/
  class Window {
  private:
    GLFWwindow* __window;
    WInterface __interface;
    int __width;
    int __height;


  public:
    Window() = default;
    ~Window();
    
    //Create a Window Context
    void create(app::Interface* app, int w, int h, const std::string &name);
    //Get the Current framebuffer Size in pixels and Set the Viewport to it    
    void setViewport();
    //Check whether window should close
    bool shouldClose();
    //Swap front and back buffers
    void swapBuffers();

    const int getWidth();
    const int getHeight();
    const float getRatio();

  };
}

#endif /* _WINDOW_H_ */
