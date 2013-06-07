//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// constants.h - useful generic constants
#pragma once

namespace mathgp
{

template <typename _type>
class constants
{
public:
    static _type PI() //pi constant
    {
        return _type(3.1415926535897932384626433832795);
    }
    static _type PI_HALF() // pi/2
    {
        return _type(1.5707963267948966192313216916398);
    }
    static _type PI_D4() // pi/4
    {
        return _type(0.78539816339744830961566084581988);
    }
    static _type PI_DBL() // 2*pi
    {
        return _type(6.283185307179586476925286766559);
    }
    static _type OVER_PI() // 1/pi
    {
        return _type(0.31830988618379067153776752674503);
    }

    static _type E() //natural constant
    {
        return _type(2.71828182845904523536028747135266249);
    }

    static _type SQRT_2() //sqrt(2)
    {
        return _type(1.4142135623730950488016887242097);
    }

    static _type EPSILON() //epsilon for floating point equalities
    {
        return _type(1e-5);
    }

    static _type EPSILON_LOW() //low precision epsilon
    {
        return _type(1e-3);
    }

    static _type EPSILON_HIGH() //high precision epsilon
    {
        return _type(1e-7);
    }
};

}
