//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// transform.h - definition of transformation functions
#pragma once

#include "vector.h"
#include "matrix.h"

namespace mathgp
{

namespace _internal
{

template <size_t _n, typename _type, typename _matrix_type, typename _vector_type>
_vector_type operator*(const matrixnxnt<_n, _type, _matrix_type>& m, vectornt<_n, _type, _vector_type>& column_vector)
{
    vectornt<_n, _type, _vector_type> result;

    for(size_t row=0; row<_n; ++row)
    {
        result.at(row) = 0;

        for(size_t col=0; col<_n; ++col)
        {
            result.at(row) += m(row, col) * column_vector.at(col);
        }
    }

    return result.as_this_type();
}

}

template <typename _type>
vector3t<_type> transform_coord(const vector3t<_type>& v, const matrix4x4t<_type>& m)
{
    vector4t<_type> transform = m * vector4t<_type>::coord(v, 1);

    return transform.homogenous_normalize().xyz();
}

}

