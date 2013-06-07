//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// ntuple.h - definition of the ntuple class
#pragma once

#include "defines.h"
#include "constants.h"
#include "functions.h"
#include <cmath>
#include <cfloat>

namespace mathgp
{

namespace _internal
{

template <size_t _n, typename _type, typename _this_type>
class ntuple
{
    static_assert(_n, "cannot create an ntuple of size 0");
public:
    typedef _type value_type;
    typedef size_t size_type;

    static const size_type value_count = _n;

    typedef void mathgp_type; // for sfinae

    ////////////////////////////////////////////////////////
    // named constructors
    static _this_type uniform(_type scalar)
    {
        _this_type ret;

        //could use memset, but it's probably slower...
        //"for" should be optimized at compile time.
        for(size_type i=0; i<value_count; ++i)
        {
            ret.at(i) = scalar;
        }

        return ret;
    }

    static _this_type zero()
    {
        return uniform(_type(0));
    }

    static _this_type from_ptr(const _type* ptr)
    {
        _this_type ret;

        //could use memcpy, but it's probably slower...
        //for should be optimized at compile time.
        MATHGP_EACH_OF(ret) = ptr[i];

        return ret;
    }

    ////////////////////////////////////////////////////////
    // attach

    static _this_type& attach_to_ptr(_type* ptr)
    {
        MATHGP_ASSERT2(ptr, "attaching ntuple to nullptr");
        return *reinterpret_cast<_this_type*>(ptr);
    }

    static const _this_type& attach_to_ptr(const _type* ptr)
    {
        MATHGP_ASSERT2(ptr, "attaching ntuple to nullptr");
        return *reinterpret_cast<const _this_type*>(ptr);
    }

    static _this_type* attach_to_array(_type* ar)
    {
        MATHGP_ASSERT2(ar, "attaching ntuple to nullptr");
        return reinterpret_cast<_this_type*>(ar);
    }

    static const _this_type* attach_to_array(const _type* ar)
    {
        MATHGP_ASSERT2(ar, "attaching ntuple to nullptr");
        return reinterpret_cast<const _this_type*>(ar);
    }

    ////////////////////////////////////////////////////////
    // access

    _type* as_array()
    {
        return values;
    }

    const _type* as_array() const
    {
        return values;
    }

    _type& at(size_type i)
    {
        MATHGP_ASSERT3(i < value_count, "ntuple index overflow");
        return values[i];
    }

    const _type& at(size_type i) const
    {
        MATHGP_ASSERT3(i < value_count, "ntuple index overflow");
        return values[i];
    }

    _type& operator[](size_type i)
    {
        return at(i);
    }

    const _type& operator[](size_type i) const
    {
        return at(i);
    }

    ////////////////////////////////////////////////////////
    // std

    typedef _type* iterator;
    typedef const _type* const_iterator;

    iterator* begin()
    {
        return as_array();
    }

    iterator* end()
    {
        return as_array() + value_count;
    }

    const_iterator* begin() const
    {
        return as_array();
    }

    const_iterator* end() const
    {
        return as_array() + value_count;
    }

    _type& front()
    {
        return at(0);
    }

    const _type& front() const
    {
        return at(0);
    }

    _type& back()
    {
        return at(value_count - 1);
    }

    const _type& back() const
    {
        return at(value_count - 1);
    }

    ////////////////////////////////////////////////////////
    // arithmetic

    const _this_type& operator+() const
    {
        return as_this_type();
    }

    _this_type operator-() const
    {
        _this_type ret;

        MATHGP_EACH_OF(ret) = -at(i);

        return ret;
    }

    _this_type& operator+=(const _this_type& b)
    {
        MATHGP_EACH_VAL += b.at(i);

        return as_this_type();
    }

    _this_type& operator-=(const _this_type& b)
    {
        MATHGP_EACH_VAL -= b.at(i);

        return as_this_type();
    }

    _this_type& operator*=(const _type& scalar)
    {
        MATHGP_EACH_VAL *= scalar;

        return as_this_type();
    }

    _this_type& operator/=(const _type& scalar)
    {
        MATHGP_ASSERT3(!::mathgp::close(scalar, _type(0)), "ntuple division by zero");

        MATHGP_EACH_VAL /= scalar;

        return as_this_type();
    }

    _this_type& as_this_type()
    {
        return *reinterpret_cast<_this_type*>(this);
    }

    const _this_type& as_this_type() const
    {
        return *reinterpret_cast<const _this_type*>(this);
    }

protected:
    _type values[value_count];
    ntuple() {};
};

template <size_t _n, typename _type, typename _this_type>
_this_type operator+(const ntuple<_n, _type, _this_type>& a,
                     const ntuple<_n, _type, _this_type>& b)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = a.at(i) + b.at(i);

    return ret;
}

template <size_t _n, typename _type, typename _this_type>
_this_type operator-(const ntuple<_n, _type, _this_type>& a,
                     const ntuple<_n, _type, _this_type>& b)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = a.at(i) - b.at(i);

    return ret;
}

template <size_t _n, typename _type, typename _this_type, typename _scalar>
typename std::enable_if<std::is_arithmetic<_scalar>::value,
_this_type>::type operator*(const ntuple<_n, _type, _this_type>& a,
                     const _scalar& scalar)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = a.at(i) * scalar;

    return ret;
}

template <size_t _n, typename _type, typename _this_type, typename _scalar>
typename std::enable_if<std::is_arithmetic<_scalar>::value,
_this_type>::type operator*(const _scalar& scalar,
                     const ntuple<_n, _type, _this_type>& b)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = scalar * b.at(i);

    return ret;
}

template <size_t _n, typename _type, typename _this_type, typename _scalar>
typename std::enable_if<std::is_arithmetic<_scalar>::value,
_this_type>::type operator/(const ntuple<_n, _type, _this_type>& a,
                     const _scalar& scalar)
{
    MATHGP_ASSERT3(!::mathgp::close(scalar, _type(0)), "ntuple division by zero");

    _this_type ret;

    MATHGP_EACH_OF(ret) = a.at(i) / scalar;

    return ret;
}

template <size_t _n, typename _type, typename _this_type>
bool operator==(const ntuple<_n, _type, _this_type>& a,
                const ntuple<_n, _type, _this_type>& b)
{
    for(size_t i=0; i<_this_type::value_count; ++i)
    {
        if(a.at(i) != b.at(i))
            return false;
    }

    return true;
}

template <size_t _n, typename _type, typename _this_type>
bool operator!=(const ntuple<_n, _type, _this_type>& a,
                const ntuple<_n, _type, _this_type>& b)
{
    return !operator==(a, b);
}

template <size_t _n, typename _type, typename _this_type>
_this_type rcp(const _type& scalar,
               const ntuple<_n, _type, _this_type>& b)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = scalar / b.at(i);

    return ret;
}

template <size_t _n, typename _type, typename _this_type>
_this_type abs(const ntuple<_n, _type, _this_type>& a)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = std::abs(a.at(i));

    return ret;
}

template <size_t _n, typename _type, typename _this_type>
bool close(const ntuple<_n, _type, _this_type>& a, const ntuple<_n, _type, _this_type>& b,
           const _type& epsilon = constants<_type>::EPSILON())
{
    for(size_t i = 0; i < _n; ++i)
        if(!::mathgp::close(a.at(i), b.at(i), epsilon))
            return false;

    return true;
}

// multiply term by term
template <size_t _n, typename _type, typename _this_type>
_this_type mul(const ntuple<_n, _type, _this_type>& a, const ntuple<_n, _type, _this_type>& b)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = a.at(i) * b.at(i);

    return true;
}

// divide term by term
template <size_t _n, typename _type, typename _this_type>
_this_type div(const ntuple<_n, _type, _this_type>& a, const ntuple<_n, _type, _this_type>& b)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = a.at(i) / b.at(i);

    return ret;
}

template <size_t _n, typename _type, typename _this_type>
bool finite(const ntuple<_n, _type, _this_type>& a)
{
    for(size_t i = 0; i < _n; ++i)
        if(!_finite(a.at(i)))
            return false;

    return true;
}

template <size_t _n, typename _type, typename _this_type>
_this_type sign(const ntuple<_n, _type, _this_type>& a)
{
    _this_type ret;

    MATHGP_EACH_OF(ret) = sign(a.at(i));

    return ret;
}

} // namespace _internal

template <typename _t>
class is_ntuple
{
    struct yes { char c; };
    struct no { char c[2]; };

    template <size_t _n, typename _type, typename _this_type>
    static yes check(_internal::ntuple<_n, _type, _this_type>*);
    static no check(...);

public:
    static const bool value = sizeof(check(static_cast<_t*>(nullptr))) == sizeof(yes);
};

// to be used if ntuples are keys in maps or sets
struct strict_ordering
{
    template <size_t _n, typename _type, typename _this_type>
    bool operator()(const _internal::ntuple<_n, _type, _this_type>& a, const _internal::ntuple<_n, _type, _this_type>& b) const
    {
        for(size_t i = 0; i < _n; ++i)
        {
            if (a.at(i) < b.at(i))
                return true;
            else if(a.at(i) > b.at(i))
                return false;
        }

        return false;
    }
};


} // namespace mathgp


