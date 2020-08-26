/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */

#include "Helper.hpp"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <vector>

namespace object {
  std::vector<helper::Vertex> getTileOfColor(glm::vec4 color);
  std::vector<unsigned int> getindicesTile();


  std::vector<helper::Vertex> getPyramide();
  std::vector<unsigned int> getIndicesPyramide(); 
}
