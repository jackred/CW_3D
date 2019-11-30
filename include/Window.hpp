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


#ifndef LYNDA_WINDOW_H_INCLUDED
#define LYNDA_WINDOW_H_INCLUDED

#include "gl_lib.hpp"
#include <iostream>


using namespace std;
namespace lynda{


  /*-----------------------------------------------------------------------------
   *  Some Callbacks to be implemented later 
   *-----------------------------------------------------------------------------*/
  struct Interface {

    static void * app; // <-- an unknown application to be defined later

    template<class APPLICATION>
    static void OnKeyDown(GLFWwindow* window, int key, int scancode, int action, int mods){
      ((APPLICATION*)(app))->onKeyDown(key,action);
    }

    template<class APPLICATION>
    static void OnMouseMove(GLFWwindow* window, double x, double y){
      ((APPLICATION*)(app))->onMouseMove(x,y);  
    }

    template<class APPLICATION>
    static void OnMouseDown(GLFWwindow* window, int button, int action, int mods){
      ((APPLICATION*)(app))->onMouseDown(button,action);
    }

  };

  void * Interface::app;



  /*-----------------------------------------------------------------------------
   *  A GLFW Window Wrapper
   *-----------------------------------------------------------------------------*/
  struct Window {

    GLFWwindow * window;
    Interface interface;

    int mWidth, mHeight;

    int width()  { return mWidth; }
    int height() { return mHeight; }
    float ratio() { return (float)mWidth/mHeight;}

    Window() {}

    //Create a Window Context
    template<class APPLICATION>
    void create(APPLICATION * app, int w, int h, const char * name="demo"){
        
      interface.app = app;

      mWidth = w; mHeight = h;

      window = glfwCreateWindow(w,h,name,NULL ,NULL);
      if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
      }        
      glfwMakeContextCurrent(window);
      glfwSwapInterval(1); //<-- force interval (not guaranteed to work with all graphics drivers)

      //register callbacks for keyboard and mouse
      glfwSetKeyCallback(window, Interface::OnKeyDown<APPLICATION>);
      glfwSetCursorPosCallback(window, Interface::OnMouseMove<APPLICATION> );
      glfwSetMouseButtonCallback(window, Interface::OnMouseDown<APPLICATION> );

    }


    //Get the Current framebuffer Size in pixels and Set the Viewport to it    
    void setViewport(){ 
      glfwGetFramebufferSize(window, &mWidth, &mHeight); 
      glViewport(0,0,mWidth,mHeight);  
    }

    //Check whether window should close
    bool shouldClose(){
      return glfwWindowShouldClose(window);
    }

    //Swap front and back buffers
    void swapBuffers(){
      glfwSwapBuffers(window);
    }

    //Destroy the window
    void destroy(){
      glfwDestroyWindow(window);
    }

    ~Window(){
      destroy();
    }
  };

} //lynda

#endif
