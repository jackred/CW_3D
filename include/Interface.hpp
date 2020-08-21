/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the MIT License. 
 * If a copy of the ML was not distributed with this
 * file, You can obtain one at https://opensource.org/licenses/MIT */
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

namespace app {

    class Interface {
    public:
        virtual void onMouseMove(double x, double y) = 0;
        virtual void onMouseDown(int button, int action) = 0;
        virtual void onMouseScroll(double x, double y) = 0;
        virtual void onKeyDown(int key, int action) = 0;
    };
}

#endif /* _INTERFACE_H_ */
