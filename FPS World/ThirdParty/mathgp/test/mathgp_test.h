//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

#pragma once

#define MAT4_CHECK_CLOSE_E(m1, m2, e) \
    BOOST_CHECK_PREDICATE( std::bind(&_internal::close<16, float, matrix>, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), (m1)(m2)(e))

#define MAT4_CHECK_CLOSE(m1, m2) MAT4_CHECK_CLOSE_E(m1, m2, constants<float>::EPSILON())

#define QUAT_CHECK_CLOSE_E(q1, q2, e) \
    BOOST_CHECK_PREDICATE( std::bind(&_internal::close<4, float, quaternion>, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), (q1)(q2)(e))

#define QUAT_CHECK_CLOSE(q1, q2) QUAT_CHECK_CLOSE_E(q1, q2, constants<float>::EPSILON())
