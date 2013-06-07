//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// internal_define.h - definitions of the internal functions used in the library
#pragma once

#include <cassert>
#include "internal_declare.h"
#include "vector.h"

namespace mathgp
{
namespace _internal
{


template <typename rotation_object, typename _type>
rotation_object rotation_from_vectors(const vector3t<_type>& src, const vector3t<_type>& target)
{
    MATHGP_ASSERT2(src.is_normalized(), "source vector should be normalized");
    MATHGP_ASSERT2(target.is_normalized(), "target vector should be normalized");
    MATHGP_ASSERT1(!close(src, vector3t<_type>::zero()), "source vector shouldn't be zero");
    MATHGP_ASSERT1(!close(target, vector3t<_type>::zero()), "target vector shouldn't be zero");

    _type cos_angle = dot(src, target);
    if (!colinear(src, target))
    {
        vector3t<_type> axis = cross(src, target);
        return rotation_object::rotation_axis(axis, std::acos(cos_angle));
    }
    else
    {
        if (cos_angle > 0)
        {
            return rotation_object::identity();
        }
        else
        {
            return rotation_object::rotation_axis(src.get_orthogonal(), constants<_type>::PI());
        }
    }
}


} // namespace _internal
} // namespace mathgp
