/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

// https://learnopengl.com/Getting-started/Camera
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <iostream>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Lib.hpp"
#include "Window.hpp"

namespace camera {

  class Camera {
  private:
    const GLfloat __minZ = 40.0f; // backward
    const GLfloat __maxZ = -40.0f; // forward
    GLfloat __radius = 0.00001f;
    float __fov = 45.0f;
    GLfloat __offsetX = 4;
    GLfloat __offsetY = 4;
    GLfloat __camX = 0;
    GLfloat __camY = 0;
    glm::vec3 __camPos = glm::vec3(__offsetX + sin(__camX) * __radius, __offsetY + cos(__camY) * __radius, __minZ);
    glm::vec3 __camFront = glm::vec3(0.0f, 0.0f, -1.0f);


    
    const float __camSpeed = 1.0f;
    void updatePos();

  public:
    Camera();
    const glm::vec3 getCamPos();
    const glm::mat4 getLookAtMatrix();
    const glm::mat4 getProjectionMatrix(window::Window& window);
    const GLfloat getRadius();

    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();

    
  };
}
#endif /* _CAMERA_H_ */
