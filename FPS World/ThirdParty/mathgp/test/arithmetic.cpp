//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//   
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

#include "precompiled.h"

using namespace boost::unit_test;
using namespace std;
using namespace mathgp;

void ntuple_arithmetic()
{
}

void vector_arithmetic()
{
    vector3 v1 = vector3::uniform(1);
    vector3 v6 = 6 * v1;

    BOOST_CHECK_EQUAL(v6, vector3::coord(6, 6, 6));    
}

void matrix_arithmetic()
{
    matrix mi = matrix::identity();

    matrix a = matrix::rows(
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16);

    matrix ai = a * mi;
    BOOST_CHECK_EQUAL(a, ai);

    ai = mi * a;
    BOOST_CHECK_EQUAL(a, ai);

    ai*=mi;
    BOOST_CHECK_EQUAL(a, ai);

    matrix b = matrix::rows(
        6, 4, 23, 11,
        16, 11, 1, 2,
        1, 1, 4, 6,
        55, 43, 21, -3
        );

    matrix c = a*b;
    BOOST_CHECK_EQUAL(c, 
        matrix::rows(
            261, 201, 121, 21,
            573, 437, 317, 85,
            885, 673, 513, 149, 
            1197, 909, 709, 213));
}

void quaternion_arithmetic()
{
    quaternion q1 = quaternion::xyzw(1, 2, 3, 4);
    quaternion q2 = quaternion::xyzw(5, 6, 7, 8);

    quaternion p = q1 * q2;

    BOOST_CHECK_EQUAL(p, quaternion::xyzw(24, 48, 48, -6));

    p = q2 * q1;

    BOOST_CHECK_EQUAL(p, quaternion::xyzw(32, 32, 56, -6));

    q1*=q2;

    BOOST_CHECK_EQUAL(q1, quaternion::xyzw(24, 48, 48, -6));
}

test_suite* arithmetic()
{
    test_suite* suite = BOOST_TEST_SUITE("arithmetic");

    suite->add(BOOST_TEST_CASE(ntuple_arithmetic));
    suite->add(BOOST_TEST_CASE(vector_arithmetic));
    suite->add(BOOST_TEST_CASE(matrix_arithmetic));
    suite->add(BOOST_TEST_CASE(quaternion_arithmetic));

    return suite;
}
