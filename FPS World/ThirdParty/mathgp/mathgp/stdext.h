//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// stdext.h - some standard library specific extensions for MathGP
#pragma once

#include <ostream>
#include "mathgp.h"

namespace mathgp
{

template <size_t _n, typename _type, typename _this_type>
::std::ostream& operator<<(::std::ostream& o, const _internal::vectornt<_n, _type, _this_type>& vec)
{
    typedef mathgp::_internal::vectornt<_n, _type, _this_type> vector;

    o << '(';
    for(typename vector::size_type i=0; i<vector::dimension; ++i)
    {
        if(i)
        {
            o << ", ";
        }

        o << vec.at(i);
    }
    o << ')';

    return o;
}

template <typename _type>
::std::ostream& operator<<(::std::ostream& o, const quaterniont<_type>& q)
{
    o << '(' << q.x() << ' ' << q.y() << ' ' << q.z() << ' ' << q.w() << ')';

    return o;
}

template <size_t _n, typename _type, typename _this_type>
inline std::ostream& operator<<(std::ostream& out, const _internal::matrixnxnt<_n, _type, _this_type>& mat)
{
    typedef _internal::matrixnxnt<_n, _type, _this_type> matrix;
    out << '(';
    for(typename matrix::size_type i=0; i<matrix::order; ++i)
    {
        if(i)
            out << ", ";

        out << mat.row_vector(i);
    }
    out << ')';
    return out;
}

}
