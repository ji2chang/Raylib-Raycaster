//
// Created by marco on 13/04/2024.
//

#ifndef RAYLIB_TEMPLATE_PORTABLE_WINDOWS_COMMON_HPP
#define RAYLIB_TEMPLATE_PORTABLE_WINDOWS_COMMON_HPP

#include "raylib.h"
namespace raycaster {
    inline double rad2deg(double x) {
        return x * 360 / (2 * PI);
    }

    inline double deg2rad(double g) {
        return g * 2*PI / 360;
    }
}


#endif //RAYLIB_TEMPLATE_PORTABLE_WINDOWS_COMMON_HPP
