//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// complex.h - a class for complex numbers
#pragma once

#include "ntuple.h"

namespace mathgp
{

template <typename _type>
class complext : public _internal::ntuple<2, _type, complext<_type>>
{
public:
    ////////////////////////////////////////////////////////
    // named constructors
    static complext values(_type r, _type i)
    {
        complext c;

        c.re() = r;
        c.im() = i;

        return c;
    }

    static complext real(_type r)
    {
        return values(r, 0);
    }

    static complext imaginary(_type i)
    {
        return values(0, i);
    }

    static complext identity()
    {
        return imaginary(1);
    }

    ////////////////////////////////////////////////////////
    // access

    _type& re()
    {
        return this->at(0);
    }

    const _type& re() const
    {
        return this->at(0);
    }

    _type& im()
    {
        return this->at(1);
    }

    const _type& im() const
    {
        return this->at(1);
    }
};

}
