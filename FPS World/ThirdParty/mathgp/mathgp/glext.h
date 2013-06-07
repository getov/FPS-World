//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// glext.h - some opengl specific extensions for the library
#pragma once

#include "matrix.h"

inline void glLoadMatrix(const mathgp::matrix4x4t<float>& m)
{
    glLoadMatrixf(m.as_array());
}

inline void glMultMatrix(const mathgp::matrix4x4t<float>& m)
{
    glMultMatrixf(m.as_array());
}
