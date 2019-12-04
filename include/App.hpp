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



#ifndef _APP_H_
#define _APP_H_

#include "Window.hpp" //<-- Our GLFW Window
#include "Interface.hpp"

namespace app {

  class App : public Interface{
  protected: // for get ratio
    window::Window __window;
  private:
    void hintsGLFW();

  public:
    App(int width, int height, const std::string &name);
    window::Window &getWindow();
    ~App();
    void start();
    virtual void onDraw();
    void onMouseMove(double x, double y) override;
    void onMouseScroll(double x, double y) override;
    void onMouseDown(int button, int action) override;
    void onKeyDown(int key, int action) override;
  };

} //app


#endif /* _APP_H_ */
