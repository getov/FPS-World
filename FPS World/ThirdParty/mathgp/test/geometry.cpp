//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

#include "precompiled.h"
#include "mathgp_test.h"

using namespace boost::unit_test;
using namespace std;
using namespace mathgp;

void matrix_algebra()
{
    matrix m1 = matrix::identity();
    BOOST_CHECK_EQUAL(m1, transpose(m1));
    BOOST_CHECK_EQUAL(m1.determinant(), 1);
    MAT4_CHECK_CLOSE(inverse(m1), m1);

    m1 = matrix::rows(
        1, 0, 0, 0,
        0, 2, 0, 0,
        0, 0, 3, 0,
        0, 0, 0, 4);
    BOOST_CHECK_EQUAL(m1.determinant(), 24);

    m1 = matrix::rows(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    matrix m2 = matrix::columns(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    BOOST_CHECK_EQUAL(m1.determinant(), 0);
    BOOST_CHECK_EQUAL(m2.determinant(), 0);
    BOOST_CHECK_EQUAL(m1, transpose(m2));
    BOOST_CHECK_EQUAL(transpose(m1), m2);

    m1 = matrix::rows(
        1, 2, 3, 4,
        5, 5, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 86);
    BOOST_CHECK_EQUAL(m1.determinant(), 1120);

    m2 = inverse(m1);
    MAT4_CHECK_CLOSE_E(inverse(m2), m1, constants<float>::EPSILON_LOW());
    MAT4_CHECK_CLOSE(m2, m1.inverse());
    MAT4_CHECK_CLOSE(m2, m1);

    MAT4_CHECK_CLOSE(m2, matrix::rows(
        -0.933929f,  0.5f, -0.073214f,  0.007143f,
         0.5f,      -1.f,   0.5f,       0.f,
         0.301786f,  0.5f, -0.280357f, -0.021429f,
         0.007143f,  0.f,  -0.021429f,  0.014286f));
}

void quaternion_geometry()
{
    quaternion q1 = quaternion::xyzw(0.5f, 0.7f, 0.212f, 0.8f);
    quaternion q2 = quaternion::xyzw(0.12f, 0.33f, 0.4f, 0.5f);

    quaternion q3 = slerp(q1, q2, 0.55f);

    QUAT_CHECK_CLOSE(q3, quaternion::xyzw(
        0.30942556881258626f, 0.527364923066248f, 0.33413672218578583f, 0.6741185090656765f));
}

void scaling()
{
    matrix m = matrix::scaling_uniform(1);
    BOOST_CHECK_EQUAL(m, matrix::identity());
}

void rotation()
{
    matrix rot;

    quaternion q = quaternion::identity();

    matrix qrot = matrix::rotation_quaternion(q);

    BOOST_CHECK(qrot.is_identity());

    q = quaternion::rotation_axis(vector3::coord(1, 2, 3), 0.15f);
    qrot = matrix::rotation_quaternion(q);
    rot = matrix::rotation_axis(vector3::coord(1, 2, 3), 0.15f);

    MAT4_CHECK_CLOSE(qrot, rot);
}

test_suite* geometry()
{
    test_suite* suite = BOOST_TEST_SUITE("geometry");

    suite->add(BOOST_TEST_CASE(matrix_algebra));
    suite->add(BOOST_TEST_CASE(quaternion_geometry));
    suite->add(BOOST_TEST_CASE(scaling));
    suite->add(BOOST_TEST_CASE(rotation));

    return suite;
}
