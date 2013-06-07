//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// quaternion.h - definition of the quaternion class
#pragma once

#include "internal_declare.h"
#include "ntuple.h"
#include "vector.h"

#include <cmath>

namespace mathgp
{

template <typename _type>
class quaterniont;

namespace _internal
{

template <typename _type>
quaterniont<_type> quaternion_multiply(const quaterniont<_type>& a, const quaterniont<_type>& b);

}


template <typename _type>
class quaterniont : public _internal::ntuple<4, _type, quaterniont<_type>>
{
public:
    ////////////////////////////////////////////////////////
    // named constructors
    static quaterniont xyzw(_type x, _type y, _type z, _type w)
    {
        quaterniont q;

        q.x() = x;
        q.y() = y;
        q.z() = z;
        q.w() = w;

        return q;
    }

    static quaterniont identity()
    {
        return xyzw(0, 0, 0, 1);
    }

    ////////////////////////////////////////////////////////
    // rotation

    static quaterniont rotation_axis(const vector3t<_type>& axis, _type radians)
    {
        const vector3t<_type> naxis = normalized(axis);
        const _type s = std::sin(radians/2);

        return xyzw(
            naxis.x() * s,
            naxis.y() * s,
            naxis.z() * s,
            std::cos(radians/2)
        );

    }

    static quaterniont rotation_yaw_pitch_roll(_type yaw, _type pitch, _type roll)
    {
        yaw/=2; pitch/=2; roll/=2;
        const _type cy = std::cos(yaw);
        const _type sy = std::sin(yaw);
        const _type cx = std::cos(pitch);
        const _type sx = std::sin(pitch);
        const _type cz = std::cos(roll);
        const _type sz = std::sin(roll);

        return xyzw(
            sx*cy*cz + cx*sy*sz,
            cx*sy*cz - sx*cy*sz,
            cx*cy*sz - sx*sy*cz,
            cx*sy*cz + sx*sy*sz
        );
    }

    static quaterniont rotation_vectors(const vector3t<_type>& src, const vector3t<_type>& target)
    {
        return _internal::rotation_from_vectors<quaterniont>(src, target);
    }

    ////////////////////////////////////////////////////////
    // access
    _type& x()
    {
        return this->at(0);
    }

    const _type& x() const
    {
        return this->at(0);
    }

    _type& y()
    {
        return this->at(1);
    }

    const _type& y() const
    {
        return this->at(1);
    }

    _type& z()
    {
        return this->at(2);
    }

    const _type& z() const
    {
        return this->at(2);
    }

    _type& w()
    {
        return this->at(3);
    }

    const _type& w() const
    {
        return this->at(3);
    }

    ////////////////////////////////////////////////////////
    // arithmetic

    quaterniont& operator*=(const quaterniont& b)
    {
        return *this = _internal::quaternion_multiply(*this, b);
    }

    ////////////////////////////////////////////////////////
    // functions
    _type magnitude_sq() const
    {
        return as_v4().length_sq();
    }

    _type magnitude() const
    {
        return as_v4().length();
    }

    _type length_sq() const //not to be confused with magnitude_sq
    {
        return as_v3().length_sq();
    }

    _type length() const //not to be confused with magnitude
    {
        return as_v3().length();
    }

    quaterniont& conjugate()
    {
        flip_sign(as_v3());

        return *this;
    }

    quaterniont& inverse()
    {
        return conjugate() /= length_sq();
    }

    quaterniont normalize()
    {
        as_v4().normalize();
        return *this;
    }

    bool is_normalized() const
    {
        return as_v4().is_normalized();
    }

    void to_axis_angle(vector3t<_type>& out_axis, _type& out_angle) const
    {
        out_angle = 2 * std::acos(w());

        _type scale = length();

        if(close(scale, 0))
        {
            out_axis = vector3t<_type>::coord(1, 0, 0);
        }
        else
        {
            // could use "normalized" but why waste a sqrt()
            out_axis = as_v3()/scale;
        }
    }

private:
    template <typename _t>
    friend _t dot(const quaterniont<_t>& a, const quaterniont<_t>& b);

    vector3t<_type>& as_v3()
    {
        return vector3t<_type>::attach_to_ptr(this->as_array());
    }

    const vector3t<_type>& as_v3() const
    {
        return vector3t<_type>::attach_to_ptr(this->as_array());
    }

    vector4t<_type>& as_v4()
    {
        return vector4t<_type>::attach_to_ptr(this->as_array());
    }

    const vector4t<_type>& as_v4() const
    {
        return vector4t<_type>::attach_to_ptr(this->as_array());
    }
};

namespace _internal
{

template <typename _type>
quaterniont<_type> quaternion_multiply(const quaterniont<_type>& a, const quaterniont<_type>& b)
{
    return quaterniont<_type>::xyzw(
        a.w()*b.x() + a.x()*b.w() + a.y()*b.z() - a.z()*b.y(),
        a.w()*b.y() - a.x()*b.z() + a.y()*b.w() + a.z()*b.x(),
        a.w()*b.z() + a.x()*b.y() - a.y()*b.x() + a.z()*b.w(),
        a.w()*b.w() - a.x()*b.x() - a.y()*b.y() - a.z()*b.z()
    );
}

}

template <typename _type>
quaterniont<_type> operator*(const quaterniont<_type>& a, const quaterniont<_type>& b)
{
    return _internal::quaternion_multiply(a, b);
}

template <typename _type>
quaterniont<_type> normalized(const quaterniont<_type>& q)
{
    return q/q.magnitude();
}

template <typename _type>
_type dot(const quaterniont<_type>& a, const quaterniont<_type>& b)
{
    return dot(a.as_v4(), b.as_v4());
}

template <typename _type>
quaterniont<_type> log(const quaterniont<_type>& q)
{
    _type angle = std::acos(q.w());
    _type s = std::sin(angle);

    _type coeff = angle/s;

    return quaterniont<_type>::xyzw(
        q.x() * coeff,
        q.y() * coeff,
        q.z() * coeff,
        0
    );
}

template <typename _type>
quaterniont<_type> exp(const quaterniont<_type>& q)
{
    _type angle = q.length();
    _type s = std::sin(angle);

    _type coeff = s/angle;

    return quaterniont<_type>::xyzw(
        q.x() * coeff,
        q.y() * coeff,
        q.z() * coeff,
        std::cos(angle)
    );
}

template <typename _type>
quaterniont<_type> lerp(const quaterniont<_type>& from, const quaterniont<_type>& to, _type ratio)
{
    return normalized(lerp<_internal::ntuple<4, _type, quaterniont<_type>>>(from, to, ratio).as_this_type());
}

template <typename _type>
quaterniont<_type> slerp(const quaterniont<_type>& from, const quaterniont<_type>& to, _type ratio)
{
    _type cos_angle = dot(from, to);

    // if the angle is small (ie cos_angle is close to -1 or 1),
    // could use lerp, instead of slerp:
    // if(cos_angle < -0.99 || cos_angle > 0.99) return lerp(from, to, ratio)
    // need to test how this works

    _type angle = std::acos(cos_angle);

    return (from*std::sin((1-ratio)*angle) + to*std::sin(angle*ratio)) / std::sin(angle);
}

}
