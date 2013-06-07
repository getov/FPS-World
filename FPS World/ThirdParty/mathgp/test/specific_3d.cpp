//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

#include "precompiled.h"

using namespace boost::unit_test;
using namespace std;
using namespace mathgp;

void projections()
{
    matrix projection = matrix::perspective_rh(2, 2, 2, 100);

    projection = matrix::ortho_rh(0, 5, 0, 5, 2, 100);

    projection = matrix::perspective_fov_rh(constants<float>::PI()/3, 1, 2, 100);
}

void views()
{
    matrix view = matrix::look_at_rh(point3::zero(), point3::coord(0, 0, -6), point3::coord(0, 1, 0));
    
    static float cam_angle = 0.5;
    static const point3 cam_center = point3::coord(0, 0, -6);
    point3 cam_pos = point3::zero();
    cam_pos.xz() = -6.f*v(std::cos(cam_angle), std::sin(cam_angle));
    cam_pos -= cam_center;

    view = matrix::look_at_rh(cam_pos, cam_center, point3::coord(0, 1, 0));
}

test_suite* specific_3d()
{
    test_suite* suite = BOOST_TEST_SUITE("specific_3d");

    suite->add(BOOST_TEST_CASE(projections));
    suite->add(BOOST_TEST_CASE(views));

    return suite;
}