//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// defines.h - macros and definitions used throughout the library
#pragma once

#include <cmath>

#define MATHGP_FOR_VALUES(counter) for(size_t counter=0; counter<_n; ++counter)

#define MATHGP_EACH_VAL for(size_t i=0; i<_n; ++i) at(i)

#define MATHGP_EACH_OF(x) for(size_t i=0; i<_n; ++i) x.at(i)

#define MATHGP_CAT(a, b) _MATHGP_INTERNAL_CAT(a, b);
#define _MATHGP_INTERNAL_CAT(a, b) a##b
