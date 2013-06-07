//                MathGP Library
//     Copyright (c) 2012 Borislav Stanimirov
//
//  See the LICENSE.txt file, included in this
//  distribution for details about the copyright

// internal_declare.h - declarations of internal functions used in the library
//    it's split in two because often they rely on multple types to be already defined
#pragma once

#include "fwd.h"

namespace mathgp
{
namespace _internal
{


template <typename rotation_object, typename _type>
rotation_object rotation_from_vectors(const vector3t<_type>& src, const vector3t<_type>& target);


} // namespace _internal
} // namespace mathgp