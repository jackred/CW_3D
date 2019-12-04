/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

#include "Camera.hpp"

camera::Camera::Camera(){
  updateCam();
}

void camera::Camera::updateCamRight() {
  __camRight = glm::normalize(glm::cross(__worldUp, __camFront));
}

void camera::Camera::updateCamUp() {
  __camUp = glm::cross(__camFront, __camRight);
}

void camera::Camera::updateCam() {
  updateCamRight();
  updateCamUp();
}

const glm::vec3 camera::Camera::getCamPos() {
  return __camPos;
}

const glm::mat4 camera::Camera::getLookAtMatrix() {
  return glm::lookAt(__camPos, __camPos + __camFront, __camUp);
}

const glm::mat4 camera::Camera::getProjectionMatrix(window::Window& window) {
  return glm::perspective(glm::radians(__fov), window.getRatio() , 0.1f, 100.0f);  
}

void camera::Camera::moveForward() {
  __camPos += __camFront * __camSpeed;
}

void camera::Camera::moveBackward() {
  __camPos -= __camFront * __camSpeed;
}

void camera::Camera::moveUp() {
  __camPos += __camUp * __camSpeed;
}

void camera::Camera::moveDown() {
  __camPos -= __camUp * __camSpeed;
}

void camera::Camera::moveLeft() {
  __camPos -= __camRight * __camSpeed;
}

void camera::Camera::moveRight() {
  __camPos += __camRight * __camSpeed;
}

void camera::Camera::rotateLeft() {
  __camFront = glm::angleAxis(__camSpeed / 6, __camUp) * __camFront;
  updateCam();
  std::cout << __camFront[0]  << " " << __camFront[1] << " " << __camFront[2] << std::endl;
}

void camera::Camera::rotateRight() {
  __camFront = glm::angleAxis(-__camSpeed / 6, __camUp) * __camFront;
  updateCam();
  std::cout << __camFront[0]  << " " << __camFront[1] << " " << __camFront[2] << std::endl;
}
