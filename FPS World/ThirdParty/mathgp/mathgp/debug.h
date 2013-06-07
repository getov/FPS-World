//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// debug.h - mathgp debugging defines
#pragma once

#include <cassert>

#define MATHGP_ASSERT_NONE 0
#define MATHGP_ASSERT_SOME 1
#define MATHGP_ASSERT_MORE 2
#define MATHGP_ASSERT_ALL  3

#if !defined(MATHGP_ASSERT_LEVEL)
#   define MATHGP_ASSERT_LEVEL MATHGP_ASSERT_ALL
#endif

#define MATHGP_NOOP ((void)0)

#if MATHGP_ASSERT_LEVEL == MATHGP_ASSERT_NONE
#   define MATHGP_ASSERT1(condition, text) MATHGP_NOOP
#   define MATHGP_ASSERT2(condition, text) MATHGP_NOOP
#   define MATHGP_ASSERT3(condition, text) MATHGP_NOOP
#elif MATHGP_ASSERT_LEVEL == MATHGP_ASSERT_SOME
#   define MATHGP_ASSERT1(condition, text) MATHGP_ASSERT(condition, text)
#   define MATHGP_ASSERT2(condition, text) MATHGP_NOOP
#   define MATHGP_ASSERT3(condition, text) MATHGP_NOOP
#elif MATHGP_ASSERT_LEVEL == MATHGP_ASSERT_MORE
#   define MATHGP_ASSERT1(condition, text) MATHGP_ASSERT(condition, text)
#   define MATHGP_ASSERT2(condition, text) MATHGP_ASSERT(condition, text)
#   define MATHGP_ASSERT3(condition, text) MATHGP_NOOP
#elif MATHGP_ASSERT_LEVEL == MATHGP_ASSERT_ALL
#   define MATHGP_ASSERT1(condition, text) MATHGP_ASSERT(condition, text)
#   define MATHGP_ASSERT2(condition, text) MATHGP_ASSERT(condition, text)
#   define MATHGP_ASSERT3(condition, text) MATHGP_ASSERT(condition, text)
#else
#   error "Invalid mathgp assertion level"
#endif

#define MATHGP_ASSERT(condition, text) assert(condition && text)
