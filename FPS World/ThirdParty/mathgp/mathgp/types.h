//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// types.h - typedefs of MathGP types for ease of use
#pragma once


#if !defined(MATHGP_PREFERRED_TYPE)
#   define MATHGP_PREFERRED_TYPE float
#endif

namespace mathgp
{

template <size_t _n, typename _type = MATHGP_PREFERRED_TYPE>
struct space
{
    typedef vector_space<_n, _type> vector;
    typedef matrix_space<_n, _type> matrix;
};

typedef vector2t<MATHGP_PREFERRED_TYPE> vector2;
typedef vector2 point2;
typedef vector2 MATHGP_CAT(MATHGP_PREFERRED_TYPE, 2);

typedef matrix2x2t<MATHGP_PREFERRED_TYPE> matrix2;
typedef matrix2 MATHGP_CAT(MATHGP_PREFERRED_TYPE, 2x2);

typedef vector3t<MATHGP_PREFERRED_TYPE> vector3;
typedef vector3 point3;
typedef vector3 MATHGP_CAT(MATHGP_PREFERRED_TYPE, 3);

typedef matrix3x3t<MATHGP_PREFERRED_TYPE> matrix3;
typedef matrix3 MATHGP_CAT(MATHGP_PREFERRED_TYPE, 3x3);

typedef vector4t<MATHGP_PREFERRED_TYPE> vector4;
typedef vector4 point4;
typedef vector4 MATHGP_CAT(MATHGP_PREFERRED_TYPE, 4);

typedef matrix4x4t<MATHGP_PREFERRED_TYPE> matrix4;
typedef matrix4 MATHGP_CAT(MATHGP_PREFERRED_TYPE, 4x4);
typedef matrix4 matrix;

typedef complext<MATHGP_PREFERRED_TYPE> complex;
typedef quaterniont<MATHGP_PREFERRED_TYPE> quaternion;

}