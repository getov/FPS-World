//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// functions.h - generic functions used throughout the library
#pragma once

#include <cmath>
#include <utility>

namespace mathgp
{

template <typename _type>
_type sq(const _type& a)
{
    return a*a;
}

template <typename _type>
void flip_sign(_type& a)
{
    a = -a;
}

template <typename _type, typename _scalar>
inline _type lerp(const _type& from, const _type& to, const _scalar ratio)
{
    return from + ratio * (to - from);
}

template <typename _type>
_type rad_to_deg(const _type& radians)
{
    return radians * (_type(180) / constants<_type>::PI());
}

template <typename _type>
_type deg_to_rad(const _type& degrees)
{
    return degrees * (constants<_type>::PI() / _type(180));
}

template <typename _type>
typename std::enable_if<std::is_arithmetic<_type>::value,
bool>::type close(const _type& a, const _type& b,
           const _type& epsilon = constants<_type>::EPSILON())
{
    return !(std::abs(a - b) > epsilon);
}

template <typename _type>
_type round(_type f)
{
    return std::floor(f+_type(0.5));
}

} // namespace mathgp
