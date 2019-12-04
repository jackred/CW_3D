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
    float __fov = 45.0f;

    glm::vec3 __camPos = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 __camFront = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 __camRight = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 __camUp = glm::vec3(0.0f, 1.0f, 0.0f);
    const glm::vec3 __worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    const float __camSpeed = 0.2f;

    void updateCamRight();
    void updateCamUp();
    void updateCam();
  public:
    Camera();
    const glm::vec3 getCamPos();
    const glm::mat4 getLookAtMatrix();
    const glm::mat4 getProjectionMatrix(window::Window& window);

    void moveForward();
    void moveBackward();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotateLeft();
    void rotateRight();

    
  };
}
#endif /* _CAMERA_H_ */
