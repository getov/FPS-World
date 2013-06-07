//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

#include "precompiled.h"

using namespace boost::unit_test;

class nrvo_test
{
public:
    static size_t copies;

    nrvo_test(int d) 
        : dummy(d)
    {}

    nrvo_test(const nrvo_test& b)
        : dummy(b.dummy)
    {
        ++copies;
    }

    int dummy;

    static nrvo_test seven()
    {
        return nrvo_test(7);
    }
};

size_t nrvo_test::copies;

void nrvo()
{
    nrvo_test t = nrvo_test::seven();
    
    BOOST_WARN_MESSAGE(nrvo_test::copies == 0, 
        "This build configuration (or your compiler) doesn't support named return "
        "value optimizations. MathGP will suffer big performance penalties because "
        "of that");
}

test_suite* prerequisites()
{
    test_suite* suite = BOOST_TEST_SUITE("prerequisites");

    suite->add(BOOST_TEST_CASE(nrvo));

    return suite;
}