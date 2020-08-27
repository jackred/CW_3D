/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#ifndef _KVSD_H_
#define _KVSD_H_

#include <vector>
#include "glm/glm.hpp"

namespace play {
  struct Play {
    std::vector<glm::vec3> pawns;
    std::vector<glm::vec3> rocks;
    std::vector<glm::vec3> bishops;
    std::vector<glm::vec3> kings;
    std::vector<glm::vec3> queens;
  };

  Play getPlay(int i);
}

#endif /* _KVSD_H_ */
