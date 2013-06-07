template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector1t<_type>::xx()
{
    return _internal::swizzle2(x(), x());
}

template <typename _type>
vector2t<_type> vector1t<_type>::xx() const
{
    return vector2t<_type>::coord(x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector1t<_type>::xxx()
{
    return _internal::swizzle3(x(), x(), x());
}

template <typename _type>
vector3t<_type> vector1t<_type>::xxx() const
{
    return vector3t<_type>::coord(x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector1t<_type>::xxxx()
{
    return _internal::swizzle4(x(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector1t<_type>::xxxx() const
{
    return vector4t<_type>::coord(x(), x(), x(), x());
}

