/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

#include "Camera.hpp"
#include <algorithm>    // std::max
camera::Camera::Camera(){
}


const glm::vec3 camera::Camera::getCamPos() {
  return __camPos;
}


const GLfloat camera::Camera::getRadius() {
  return __radius;
}

const glm::mat4 camera::Camera::getLookAtMatrix() {
  return glm::lookAt(__camPos, glm::vec3(__offsetX, __offsetY, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

const glm::mat4 camera::Camera::getProjectionMatrix(window::Window& window) {
  return glm::perspective(glm::radians(__fov), window.getRatio() , 0.1f, 100.0f);  
}

void camera::Camera::moveForward() {
  GLfloat tmp = __camPos[2] - __camSpeed;
  if (tmp >= __maxZ){
    __camPos[2] = tmp;
    __radius += __camSpeed;
  } else {
    __camPos[2] = __maxZ;
  }
  updatePos();
}

void camera::Camera::moveBackward() {
  GLfloat tmp = __camPos[2] + __camSpeed;
  if (tmp <= __minZ){
    __camPos[2] = tmp;
    __radius = std::max(0.1f, __radius - __camSpeed);
  } else {
    __camPos[2] = __minZ;
  }
  updatePos();
}


void camera::Camera::moveLeft() {
  __camX -= 0.1 * __camSpeed;
  __camY -=0.1 * __camSpeed;
  updatePos();
}

void camera::Camera::moveRight() {
  __camX += 0.1 * __camSpeed;
  __camY += 0.1 * __camSpeed;
  updatePos();
}


void camera::Camera::updatePos() {
  __camPos[0] = __offsetX + sin(__camX) * __radius;
  __camPos[1] = __offsetY + cos(__camY) * __radius;
}

