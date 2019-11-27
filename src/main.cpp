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

//Include OpenGL for graphics and Glfw for windowing
#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <iostream>


int main(){

    if( !glfwInit() ) exit(EXIT_FAILURE);

    int w = 1024; int h = 768;

    GLFWwindow * window;             //Create Window (use glfwGetPrimaryMonitor() for fullscreen)
    window = glfwCreateWindow(w,h,"glfw",NULL,NULL);

    if (!window) {                   //Check Validity
      glfwTerminate();
      exit(EXIT_FAILURE);
    }        
    glfwMakeContextCurrent(window);  //Make Window Current Context


    printf("hello window\n");

 
    while ( !glfwWindowShouldClose(window) ){
        glViewport(0,0,w/2,h/2);             //Set Viewport in pixels
        glClearColor(0.5,0.5,0,1);           //CLEAR WINDOW CONTENTS
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //put drawing code in here

        glfwSwapBuffers(window);                //<-- SWAP BUFFERS
        glfwPollEvents();                       //<-- LISTEN FOR WINDOW EVENTS
    }
  
    //Destroy window and terminate glfw
    glfwDestroyWindow(window);
    glfwTerminate();
    printf("goodbye window\n");

  return 0;
}
