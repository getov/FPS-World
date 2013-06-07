template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector2t<_type>::xx()
{
    return _internal::swizzle2(x(), x());
}

template <typename _type>
vector2t<_type> vector2t<_type>::xx() const
{
    return vector2t<_type>::coord(x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector2t<_type>::yx()
{
    return _internal::swizzle2(y(), x());
}

template <typename _type>
vector2t<_type> vector2t<_type>::yx() const
{
    return vector2t<_type>::coord(y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector2t<_type>::yy()
{
    return _internal::swizzle2(y(), y());
}

template <typename _type>
vector2t<_type> vector2t<_type>::yy() const
{
    return vector2t<_type>::coord(y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::xxx()
{
    return _internal::swizzle3(x(), x(), x());
}

template <typename _type>
vector3t<_type> vector2t<_type>::xxx() const
{
    return vector3t<_type>::coord(x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::xxy()
{
    return _internal::swizzle3(x(), x(), y());
}

template <typename _type>
vector3t<_type> vector2t<_type>::xxy() const
{
    return vector3t<_type>::coord(x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::xyx()
{
    return _internal::swizzle3(x(), y(), x());
}

template <typename _type>
vector3t<_type> vector2t<_type>::xyx() const
{
    return vector3t<_type>::coord(x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::xyy()
{
    return _internal::swizzle3(x(), y(), y());
}

template <typename _type>
vector3t<_type> vector2t<_type>::xyy() const
{
    return vector3t<_type>::coord(x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::yxx()
{
    return _internal::swizzle3(y(), x(), x());
}

template <typename _type>
vector3t<_type> vector2t<_type>::yxx() const
{
    return vector3t<_type>::coord(y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::yxy()
{
    return _internal::swizzle3(y(), x(), y());
}

template <typename _type>
vector3t<_type> vector2t<_type>::yxy() const
{
    return vector3t<_type>::coord(y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::yyx()
{
    return _internal::swizzle3(y(), y(), x());
}

template <typename _type>
vector3t<_type> vector2t<_type>::yyx() const
{
    return vector3t<_type>::coord(y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector2t<_type>::yyy()
{
    return _internal::swizzle3(y(), y(), y());
}

template <typename _type>
vector3t<_type> vector2t<_type>::yyy() const
{
    return vector3t<_type>::coord(y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xxxx()
{
    return _internal::swizzle4(x(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xxxx() const
{
    return vector4t<_type>::coord(x(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xxxy()
{
    return _internal::swizzle4(x(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xxxy() const
{
    return vector4t<_type>::coord(x(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xxyx()
{
    return _internal::swizzle4(x(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xxyx() const
{
    return vector4t<_type>::coord(x(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xxyy()
{
    return _internal::swizzle4(x(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xxyy() const
{
    return vector4t<_type>::coord(x(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xyxx()
{
    return _internal::swizzle4(x(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xyxx() const
{
    return vector4t<_type>::coord(x(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xyxy()
{
    return _internal::swizzle4(x(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xyxy() const
{
    return vector4t<_type>::coord(x(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xyyx()
{
    return _internal::swizzle4(x(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xyyx() const
{
    return vector4t<_type>::coord(x(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::xyyy()
{
    return _internal::swizzle4(x(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::xyyy() const
{
    return vector4t<_type>::coord(x(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yxxx()
{
    return _internal::swizzle4(y(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yxxx() const
{
    return vector4t<_type>::coord(y(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yxxy()
{
    return _internal::swizzle4(y(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yxxy() const
{
    return vector4t<_type>::coord(y(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yxyx()
{
    return _internal::swizzle4(y(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yxyx() const
{
    return vector4t<_type>::coord(y(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yxyy()
{
    return _internal::swizzle4(y(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yxyy() const
{
    return vector4t<_type>::coord(y(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yyxx()
{
    return _internal::swizzle4(y(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yyxx() const
{
    return vector4t<_type>::coord(y(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yyxy()
{
    return _internal::swizzle4(y(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yyxy() const
{
    return vector4t<_type>::coord(y(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yyyx()
{
    return _internal::swizzle4(y(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yyyx() const
{
    return vector4t<_type>::coord(y(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector2t<_type>::yyyy()
{
    return _internal::swizzle4(y(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector2t<_type>::yyyy() const
{
    return vector4t<_type>::coord(y(), y(), y(), y());
}

