//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// platform.h - some platform dependent checks and defines
#pragma once

////////////////////////////////////////////////////////
// compiler specific stuff

#if defined(_MSC_VER)
#   if _MSC_VER < 1600
#       error "A minimum cl version of 16 is required to compile MathGP"
#   endif
#elif defined(__GNUC__)
    #if __GNUC__ < 4 || __GNUC_MINOR__ < 5 || __GNUC_PATCHLEVEL__ < 2
        #error "A minimum gcc version of 4.5.2 is required to compile MathGP"
    #elif __GNUC_MINOR__ < 6
        // can be emulated through
        // http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/nullptr#Solution_and_Sample_Code
        // but no need to maintain a global variable.
        // the define is fine for now
        #define nullptr NULL
    #endif
#endif
