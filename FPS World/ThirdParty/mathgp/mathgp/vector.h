//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// vector.h - definition of the vector classes
#pragma once

#include "constants.h"
#include "ntuple.h"
#include "fwd.h"

namespace mathgp
{
namespace _internal
{

template <size_t _n, typename _type, typename _this_type>
class vectornt : public ntuple<_n, _type, _this_type>
{
    //typedef ntuple<_n, _type, _this_type> parent;
public:
    static const size_t dimension = _n;

    _type length_sq() const
    {
        _type result = 0;

        MATHGP_FOR_VALUES(i)
            result += sq(this->at(i));

        return result;
    }

    _type length() const
    {
        return std::sqrt(length_sq());
    }

    _this_type& normalize()
    {
        MATHGP_ASSERT3(!::mathgp::close(length(), _type(0)), "normalizing a zero-length vector");
        return this->as_this_type() /= length();
    }

    bool is_normalized() const
    {
        return ::mathgp::close(length(), _type(1));
    }

    _this_type& homogenous_normalize()
    {
        static_assert(dimension > 1, "you need at least two homogenous coordinates");
        MATHGP_ASSERT3(!::mathgp::close(this->back(), _type(0)), "homogenous normalize with a zero homogenous coordinate");

        return this->as_this_type() /= this->back();
    }

    _this_type get_reflection(const vectornt<_n, _type, _this_type>& normal) const
    {
        MATHGP_ASSERT3(normal.is_normalized(), "reflecting with a non-normalized normal");
        return *this - _type(2) * dot(*this, normal) * normal;
    }
};

template <size_t _n, typename _type, typename _this_type>
_type dot(const vectornt<_n, _type, _this_type>& a, const vectornt<_n, _type, _this_type>& b)
{
    _type result = 0;

    MATHGP_FOR_VALUES(i)
        result += a.at(i) * b.at(i);

    return result;
}

template <size_t _dim, typename _type, typename _this_type>
bool orthogonal(const vectornt<_dim, _type, _this_type>& a, const vectornt<_dim, _type, _this_type>& b)
{
    return close(dot(a, b), 0);
}

template <typename _type, typename _this_type>
bool colinear(const vectornt<3, _type, _this_type>& a, const vectornt<3, _type, _this_type>& b)
{
    // there are many ways to do this, but to save sqrt calls let's try this
    _this_type adb = div(a, b);

    return ::mathgp::close(adb.x(), adb.y()) && ::mathgp::close(adb.x(), adb.z());
}


template <size_t _n, typename _type, typename _this_type>
_this_type normalized(const vectornt<_n, _type, _this_type>& a)
{
    _type length = a.length();

    MATHGP_ASSERT3(!::mathgp::close(length, _type(0)), "normalizing a zero-length vector");

    _this_type ret;

    MATHGP_EACH_OF(ret) = a.at(i) / length;

    return ret;
}

template <size_t _dim, typename _type, typename _this_type>
_type distance_sq(const vectornt<_dim, _type, _this_type>& a, const vectornt<_dim, _type, _this_type>& b)
{
    return (b-a).length_sq();
}

template <size_t _dim, typename _type, typename _this_type>
_type distance(const vectornt<_dim, _type, _this_type>& a, const vectornt<_dim, _type, _this_type>& b)
{
    return (b-a).length();
}


#if !defined(MATHGP_DISABLE_SWIZZLE)

template <typename _type>
class wrap_ref
{
public:
    operator _type&()
    {
        return *ref;
    }

    operator const _type&() const
    {
        return *ref;
    }

    _type* ref;
};


template <size_t _n, typename _type, typename _this_type>
class swizzle_vectornt : public vectornt<_n, wrap_ref<_type>, _this_type>
{
public:

    operator _this_type() const
    {
        _this_type ret;

        MATHGP_EACH_OF(ret) = this->at(i);

        return ret;
    }

    // intentionally void
    // it breaks a=b=c, but gets rid of unwanted temporary objects
    void operator=(const vectornt<_n, _type, _this_type>& b)
    {
        for(size_t i=0; i<_n; ++i)
            *this->at(i).ref = b.at(i);
    }

private:
    ////////////////////////////////////////////////////////
    // unsafe operators to be hidden
};

#endif // #if !defined(MATHGP_DISABLE_SWIZZLE)

} // namespace _internal

template <typename _type>
class vector1t : public _internal::vectornt<1, _type, vector1t<_type>>
{
public:
    ////////////////////////////////////////////////////////
    // named constructors

    static vector1t coord(_type x)
    {
        vector1t ret;

        ret.x() = x;

        return ret;
    }

#include "vector1_swizzle.inl"

#if !defined(MATHGP_DISABLE_SWIZZLE)
#   include "vector1_swizzle_declare.inl" // generated file
#endif

};

template <typename _type>
vector1t<_type> v(const _type& x)
{
    return vector1t<_type>::coord(x);
}

template <typename _type>
class vector2t : public _internal::vectornt<2, _type, vector2t<_type>>
{
public:
    ////////////////////////////////////////////////////////
    // named constructors

    static vector2t coord(_type x, _type y)
    {
        vector2t ret;

        ret.x() = x;
        ret.y() = y;

        return ret;
    }

    ////////////////////////////////////////////////////////
    // functions

    vector2t get_orthogonal() const
    {
        MATHGP_ASSERT3(!close(*this, vector2t::zero()), "finding an orthogonal of a zero vector");
        return vector2t::coord(-y(), x());
    }

#include "vector1_swizzle.inl"
#include "vector2_swizzle.inl"

#if !defined(MATHGP_DISABLE_SWIZZLE)
#   include "vector2_swizzle_declare.inl" // generated file
#endif

};

template <typename _type>
vector2t<_type> v(const _type& x, const _type& y)
{
    return vector2t<_type>::coord(x, y);
}

template <typename _type>
_type cross_magnitude(const vector2t<_type>& a, const vector2t<_type>& b)
{
    return a.x*b.y - a.y*b.x;
}

template <typename _type>
class vector3t : public _internal::vectornt<3, _type, vector3t<_type>>
{
public:
    ////////////////////////////////////////////////////////
    // named constructors

    static vector3t coord(_type x, _type y, _type z)
    {
        vector3t ret;

        ret.x() = x;
        ret.y() = y;
        ret.z() = z;

        return ret;
    }

    ////////////////////////////////////////////////////////
    // functions
    vector3t& change_handedness()
    {
        flip_sign(z());
        return *this;
    }

    vector3t get_orthogonal() const
    {
        size_t non_zeros = 0;
        size_t non_zero_index = 0;

        for (size_t i=0; i<3; ++i)
        {
            if (std::abs(this->at(i)) > constants<_type>::EPSILON())
            {
                ++non_zeros;
                non_zero_index = i;
            }
        }

        MATHGP_ASSERT3(non_zeros, "finding an orthogonal of a zero vector");

        if (non_zeros >= 2)
        {
            return vector3t::coord(y() * z() / 2, x() * z() / 2, -x() * y());
        }
        else
        {
            vector3t ret = vector3t::zero();

            ret.at((non_zero_index + 1) % 3) = this->at(non_zero_index);
            return ret;
        }
    }

#include "vector1_swizzle.inl"
#include "vector2_swizzle.inl"
#include "vector3_swizzle.inl"

#if !defined(MATHGP_DISABLE_SWIZZLE)
#   include "vector3_swizzle_declare.inl" // generated file
#endif

};

template <typename _type>
vector3t<_type> v(const _type& x, const _type& y, const _type& z)
{
    return vector3t<_type>::coord(x, y, z);
}

template <typename _type>
vector3t<_type> cross(const vector3t<_type>& a, const vector3t<_type>& b)
{
    MATHGP_ASSERT3(!close(a, vector3t<_type>::zero()), "cross product with a zero vector");
    MATHGP_ASSERT3(!close(b, vector3t<_type>::zero()), "cross product with a zero vector");

    return vector3t<_type>::coord(
        a.y()*b.z() - a.z()*b.y(),
        a.z()*b.x() - a.x()*b.z(),
        a.x()*b.y() - a.y()*b.x()
    );
}

template <typename _type>
class vector4t : public _internal::vectornt<4, _type, vector4t<_type>>
{
public:
    ////////////////////////////////////////////////////////
    // named constructors

    static vector4t coord(_type x, _type y, _type z, _type w)
    {
        vector4t ret;

        ret.x() = x;
        ret.y() = y;
        ret.z() = z;
        ret.w() = w;

        return ret;
    }

    static vector4t coord(const vector3t<_type>& v3, _type w)
    {
        return coord(v3.x(), v3.y(), v3.z(), w);
    }

#include "vector1_swizzle.inl"
#include "vector2_swizzle.inl"
#include "vector3_swizzle.inl"
#include "vector4_swizzle.inl"

#if !defined(MATHGP_DISABLE_SWIZZLE)
#   include "vector4_swizzle_declare.inl" // generated file
#endif

};

template <typename _type>
vector4t<_type> v(const _type& x, const _type& y, const _type& z, const _type& w)
{
    return vector4t<_type>::coord(x, y, z, w);
}


#if !defined(MATHGP_DISABLE_SWIZZLE)

namespace _internal
{

template <typename _type>
swizzle_vectornt<2, _type, vector2t<_type>> swizzle2(_type& x, _type& y)
{
    swizzle_vectornt<2, _type, vector2t<_type>> ret;

    ret.at(0).ref = &x;
    ret.at(1).ref = &y;

    return ret;
}

template <typename _type>
swizzle_vectornt<3, _type, vector3t<_type>> swizzle3(_type& x, _type& y, _type& z)
{
    swizzle_vectornt<3, _type, vector3t<_type>> ret;

    ret.at(0).ref = &x;
    ret.at(1).ref = &y;
    ret.at(2).ref = &z;

    return ret;
}

template <typename _type>
swizzle_vectornt<4, _type, vector4t<_type>> swizzle4(_type& x, _type& y, _type& z, _type& w)
{
    swizzle_vectornt<4, _type, vector4t<_type>> ret;

    ret.at(0).ref = &x;
    ret.at(1).ref = &y;
    ret.at(2).ref = &z;
    ret.at(3).ref = &w;

    return ret;
}

} // namespace internal


#   include "vector1_swizzle_define.inl"
#   include "vector2_swizzle_define.inl"
#   include "vector3_swizzle_define.inl"
#   include "vector4_swizzle_define.inl"

#endif // #if !defined(MATHGP_DISABLE_SWIZZLE)

template <size_t _dim, typename _type>
class vectorntx : public _internal::vectornt<_dim, _type, vectorntx<_dim, _type>>
{
public:
};

template <size_t _dim, typename _type>
struct vector_space
{
    typedef vectorntx<_dim, _type> vector;
};

template <typename _type>
struct vector_space<1, _type>
{
    typedef vector1t<_type> vector;
};

template <typename _type>
struct vector_space<2, _type>
{
    typedef vector2t<_type> vector;
};

template <typename _type>
struct vector_space<3, _type>
{
    typedef vector3t<_type> vector;
};

template <typename _type>
struct vector_space<4, _type>
{
    typedef vector4t<_type> vector;
};

} // namespace mathgp
