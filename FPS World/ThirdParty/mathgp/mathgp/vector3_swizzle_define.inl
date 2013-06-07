template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector3t<_type>::xx()
{
    return _internal::swizzle2(x(), x());
}

template <typename _type>
vector2t<_type> vector3t<_type>::xx() const
{
    return vector2t<_type>::coord(x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector3t<_type>::xz()
{
    return _internal::swizzle2(x(), z());
}

template <typename _type>
vector2t<_type> vector3t<_type>::xz() const
{
    return vector2t<_type>::coord(x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector3t<_type>::yx()
{
    return _internal::swizzle2(y(), x());
}

template <typename _type>
vector2t<_type> vector3t<_type>::yx() const
{
    return vector2t<_type>::coord(y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector3t<_type>::yy()
{
    return _internal::swizzle2(y(), y());
}

template <typename _type>
vector2t<_type> vector3t<_type>::yy() const
{
    return vector2t<_type>::coord(y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector3t<_type>::zx()
{
    return _internal::swizzle2(z(), x());
}

template <typename _type>
vector2t<_type> vector3t<_type>::zx() const
{
    return vector2t<_type>::coord(z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector3t<_type>::zy()
{
    return _internal::swizzle2(z(), y());
}

template <typename _type>
vector2t<_type> vector3t<_type>::zy() const
{
    return vector2t<_type>::coord(z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<2, _type, vector2t<_type>> vector3t<_type>::zz()
{
    return _internal::swizzle2(z(), z());
}

template <typename _type>
vector2t<_type> vector3t<_type>::zz() const
{
    return vector2t<_type>::coord(z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xxx()
{
    return _internal::swizzle3(x(), x(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xxx() const
{
    return vector3t<_type>::coord(x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xxy()
{
    return _internal::swizzle3(x(), x(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xxy() const
{
    return vector3t<_type>::coord(x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xxz()
{
    return _internal::swizzle3(x(), x(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xxz() const
{
    return vector3t<_type>::coord(x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xyx()
{
    return _internal::swizzle3(x(), y(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xyx() const
{
    return vector3t<_type>::coord(x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xyy()
{
    return _internal::swizzle3(x(), y(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xyy() const
{
    return vector3t<_type>::coord(x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xzx()
{
    return _internal::swizzle3(x(), z(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xzx() const
{
    return vector3t<_type>::coord(x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xzy()
{
    return _internal::swizzle3(x(), z(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xzy() const
{
    return vector3t<_type>::coord(x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::xzz()
{
    return _internal::swizzle3(x(), z(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::xzz() const
{
    return vector3t<_type>::coord(x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yxx()
{
    return _internal::swizzle3(y(), x(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yxx() const
{
    return vector3t<_type>::coord(y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yxy()
{
    return _internal::swizzle3(y(), x(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yxy() const
{
    return vector3t<_type>::coord(y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yxz()
{
    return _internal::swizzle3(y(), x(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yxz() const
{
    return vector3t<_type>::coord(y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yyx()
{
    return _internal::swizzle3(y(), y(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yyx() const
{
    return vector3t<_type>::coord(y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yyy()
{
    return _internal::swizzle3(y(), y(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yyy() const
{
    return vector3t<_type>::coord(y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yyz()
{
    return _internal::swizzle3(y(), y(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yyz() const
{
    return vector3t<_type>::coord(y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yzx()
{
    return _internal::swizzle3(y(), z(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yzx() const
{
    return vector3t<_type>::coord(y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yzy()
{
    return _internal::swizzle3(y(), z(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yzy() const
{
    return vector3t<_type>::coord(y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::yzz()
{
    return _internal::swizzle3(y(), z(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::yzz() const
{
    return vector3t<_type>::coord(y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zxx()
{
    return _internal::swizzle3(z(), x(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zxx() const
{
    return vector3t<_type>::coord(z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zxy()
{
    return _internal::swizzle3(z(), x(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zxy() const
{
    return vector3t<_type>::coord(z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zxz()
{
    return _internal::swizzle3(z(), x(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zxz() const
{
    return vector3t<_type>::coord(z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zyx()
{
    return _internal::swizzle3(z(), y(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zyx() const
{
    return vector3t<_type>::coord(z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zyy()
{
    return _internal::swizzle3(z(), y(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zyy() const
{
    return vector3t<_type>::coord(z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zyz()
{
    return _internal::swizzle3(z(), y(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zyz() const
{
    return vector3t<_type>::coord(z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zzx()
{
    return _internal::swizzle3(z(), z(), x());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zzx() const
{
    return vector3t<_type>::coord(z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zzy()
{
    return _internal::swizzle3(z(), z(), y());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zzy() const
{
    return vector3t<_type>::coord(z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<3, _type, vector3t<_type>> vector3t<_type>::zzz()
{
    return _internal::swizzle3(z(), z(), z());
}

template <typename _type>
vector3t<_type> vector3t<_type>::zzz() const
{
    return vector3t<_type>::coord(z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxxx()
{
    return _internal::swizzle4(x(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxxx() const
{
    return vector4t<_type>::coord(x(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxxy()
{
    return _internal::swizzle4(x(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxxy() const
{
    return vector4t<_type>::coord(x(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxxz()
{
    return _internal::swizzle4(x(), x(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxxz() const
{
    return vector4t<_type>::coord(x(), x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxyx()
{
    return _internal::swizzle4(x(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxyx() const
{
    return vector4t<_type>::coord(x(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxyy()
{
    return _internal::swizzle4(x(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxyy() const
{
    return vector4t<_type>::coord(x(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxyz()
{
    return _internal::swizzle4(x(), x(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxyz() const
{
    return vector4t<_type>::coord(x(), x(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxzx()
{
    return _internal::swizzle4(x(), x(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxzx() const
{
    return vector4t<_type>::coord(x(), x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxzy()
{
    return _internal::swizzle4(x(), x(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxzy() const
{
    return vector4t<_type>::coord(x(), x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xxzz()
{
    return _internal::swizzle4(x(), x(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xxzz() const
{
    return vector4t<_type>::coord(x(), x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyxx()
{
    return _internal::swizzle4(x(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyxx() const
{
    return vector4t<_type>::coord(x(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyxy()
{
    return _internal::swizzle4(x(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyxy() const
{
    return vector4t<_type>::coord(x(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyxz()
{
    return _internal::swizzle4(x(), y(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyxz() const
{
    return vector4t<_type>::coord(x(), y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyyx()
{
    return _internal::swizzle4(x(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyyx() const
{
    return vector4t<_type>::coord(x(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyyy()
{
    return _internal::swizzle4(x(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyyy() const
{
    return vector4t<_type>::coord(x(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyyz()
{
    return _internal::swizzle4(x(), y(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyyz() const
{
    return vector4t<_type>::coord(x(), y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyzx()
{
    return _internal::swizzle4(x(), y(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyzx() const
{
    return vector4t<_type>::coord(x(), y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyzy()
{
    return _internal::swizzle4(x(), y(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyzy() const
{
    return vector4t<_type>::coord(x(), y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xyzz()
{
    return _internal::swizzle4(x(), y(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xyzz() const
{
    return vector4t<_type>::coord(x(), y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzxx()
{
    return _internal::swizzle4(x(), z(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzxx() const
{
    return vector4t<_type>::coord(x(), z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzxy()
{
    return _internal::swizzle4(x(), z(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzxy() const
{
    return vector4t<_type>::coord(x(), z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzxz()
{
    return _internal::swizzle4(x(), z(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzxz() const
{
    return vector4t<_type>::coord(x(), z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzyx()
{
    return _internal::swizzle4(x(), z(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzyx() const
{
    return vector4t<_type>::coord(x(), z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzyy()
{
    return _internal::swizzle4(x(), z(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzyy() const
{
    return vector4t<_type>::coord(x(), z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzyz()
{
    return _internal::swizzle4(x(), z(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzyz() const
{
    return vector4t<_type>::coord(x(), z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzzx()
{
    return _internal::swizzle4(x(), z(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzzx() const
{
    return vector4t<_type>::coord(x(), z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzzy()
{
    return _internal::swizzle4(x(), z(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzzy() const
{
    return vector4t<_type>::coord(x(), z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::xzzz()
{
    return _internal::swizzle4(x(), z(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::xzzz() const
{
    return vector4t<_type>::coord(x(), z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxxx()
{
    return _internal::swizzle4(y(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxxx() const
{
    return vector4t<_type>::coord(y(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxxy()
{
    return _internal::swizzle4(y(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxxy() const
{
    return vector4t<_type>::coord(y(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxxz()
{
    return _internal::swizzle4(y(), x(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxxz() const
{
    return vector4t<_type>::coord(y(), x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxyx()
{
    return _internal::swizzle4(y(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxyx() const
{
    return vector4t<_type>::coord(y(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxyy()
{
    return _internal::swizzle4(y(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxyy() const
{
    return vector4t<_type>::coord(y(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxyz()
{
    return _internal::swizzle4(y(), x(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxyz() const
{
    return vector4t<_type>::coord(y(), x(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxzx()
{
    return _internal::swizzle4(y(), x(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxzx() const
{
    return vector4t<_type>::coord(y(), x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxzy()
{
    return _internal::swizzle4(y(), x(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxzy() const
{
    return vector4t<_type>::coord(y(), x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yxzz()
{
    return _internal::swizzle4(y(), x(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yxzz() const
{
    return vector4t<_type>::coord(y(), x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyxx()
{
    return _internal::swizzle4(y(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyxx() const
{
    return vector4t<_type>::coord(y(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyxy()
{
    return _internal::swizzle4(y(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyxy() const
{
    return vector4t<_type>::coord(y(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyxz()
{
    return _internal::swizzle4(y(), y(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyxz() const
{
    return vector4t<_type>::coord(y(), y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyyx()
{
    return _internal::swizzle4(y(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyyx() const
{
    return vector4t<_type>::coord(y(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyyy()
{
    return _internal::swizzle4(y(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyyy() const
{
    return vector4t<_type>::coord(y(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyyz()
{
    return _internal::swizzle4(y(), y(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyyz() const
{
    return vector4t<_type>::coord(y(), y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyzx()
{
    return _internal::swizzle4(y(), y(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyzx() const
{
    return vector4t<_type>::coord(y(), y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyzy()
{
    return _internal::swizzle4(y(), y(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyzy() const
{
    return vector4t<_type>::coord(y(), y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yyzz()
{
    return _internal::swizzle4(y(), y(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yyzz() const
{
    return vector4t<_type>::coord(y(), y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzxx()
{
    return _internal::swizzle4(y(), z(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzxx() const
{
    return vector4t<_type>::coord(y(), z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzxy()
{
    return _internal::swizzle4(y(), z(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzxy() const
{
    return vector4t<_type>::coord(y(), z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzxz()
{
    return _internal::swizzle4(y(), z(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzxz() const
{
    return vector4t<_type>::coord(y(), z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzyx()
{
    return _internal::swizzle4(y(), z(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzyx() const
{
    return vector4t<_type>::coord(y(), z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzyy()
{
    return _internal::swizzle4(y(), z(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzyy() const
{
    return vector4t<_type>::coord(y(), z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzyz()
{
    return _internal::swizzle4(y(), z(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzyz() const
{
    return vector4t<_type>::coord(y(), z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzzx()
{
    return _internal::swizzle4(y(), z(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzzx() const
{
    return vector4t<_type>::coord(y(), z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzzy()
{
    return _internal::swizzle4(y(), z(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzzy() const
{
    return vector4t<_type>::coord(y(), z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::yzzz()
{
    return _internal::swizzle4(y(), z(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::yzzz() const
{
    return vector4t<_type>::coord(y(), z(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxxx()
{
    return _internal::swizzle4(z(), x(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxxx() const
{
    return vector4t<_type>::coord(z(), x(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxxy()
{
    return _internal::swizzle4(z(), x(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxxy() const
{
    return vector4t<_type>::coord(z(), x(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxxz()
{
    return _internal::swizzle4(z(), x(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxxz() const
{
    return vector4t<_type>::coord(z(), x(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxyx()
{
    return _internal::swizzle4(z(), x(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxyx() const
{
    return vector4t<_type>::coord(z(), x(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxyy()
{
    return _internal::swizzle4(z(), x(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxyy() const
{
    return vector4t<_type>::coord(z(), x(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxyz()
{
    return _internal::swizzle4(z(), x(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxyz() const
{
    return vector4t<_type>::coord(z(), x(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxzx()
{
    return _internal::swizzle4(z(), x(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxzx() const
{
    return vector4t<_type>::coord(z(), x(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxzy()
{
    return _internal::swizzle4(z(), x(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxzy() const
{
    return vector4t<_type>::coord(z(), x(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zxzz()
{
    return _internal::swizzle4(z(), x(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zxzz() const
{
    return vector4t<_type>::coord(z(), x(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyxx()
{
    return _internal::swizzle4(z(), y(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyxx() const
{
    return vector4t<_type>::coord(z(), y(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyxy()
{
    return _internal::swizzle4(z(), y(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyxy() const
{
    return vector4t<_type>::coord(z(), y(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyxz()
{
    return _internal::swizzle4(z(), y(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyxz() const
{
    return vector4t<_type>::coord(z(), y(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyyx()
{
    return _internal::swizzle4(z(), y(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyyx() const
{
    return vector4t<_type>::coord(z(), y(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyyy()
{
    return _internal::swizzle4(z(), y(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyyy() const
{
    return vector4t<_type>::coord(z(), y(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyyz()
{
    return _internal::swizzle4(z(), y(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyyz() const
{
    return vector4t<_type>::coord(z(), y(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyzx()
{
    return _internal::swizzle4(z(), y(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyzx() const
{
    return vector4t<_type>::coord(z(), y(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyzy()
{
    return _internal::swizzle4(z(), y(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyzy() const
{
    return vector4t<_type>::coord(z(), y(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zyzz()
{
    return _internal::swizzle4(z(), y(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zyzz() const
{
    return vector4t<_type>::coord(z(), y(), z(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzxx()
{
    return _internal::swizzle4(z(), z(), x(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzxx() const
{
    return vector4t<_type>::coord(z(), z(), x(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzxy()
{
    return _internal::swizzle4(z(), z(), x(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzxy() const
{
    return vector4t<_type>::coord(z(), z(), x(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzxz()
{
    return _internal::swizzle4(z(), z(), x(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzxz() const
{
    return vector4t<_type>::coord(z(), z(), x(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzyx()
{
    return _internal::swizzle4(z(), z(), y(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzyx() const
{
    return vector4t<_type>::coord(z(), z(), y(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzyy()
{
    return _internal::swizzle4(z(), z(), y(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzyy() const
{
    return vector4t<_type>::coord(z(), z(), y(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzyz()
{
    return _internal::swizzle4(z(), z(), y(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzyz() const
{
    return vector4t<_type>::coord(z(), z(), y(), z());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzzx()
{
    return _internal::swizzle4(z(), z(), z(), x());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzzx() const
{
    return vector4t<_type>::coord(z(), z(), z(), x());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzzy()
{
    return _internal::swizzle4(z(), z(), z(), y());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzzy() const
{
    return vector4t<_type>::coord(z(), z(), z(), y());
}

template <typename _type>
_internal::swizzle_vectornt<4, _type, vector4t<_type>> vector3t<_type>::zzzz()
{
    return _internal::swizzle4(z(), z(), z(), z());
}

template <typename _type>
vector4t<_type> vector3t<_type>::zzzz() const
{
    return vector4t<_type>::coord(z(), z(), z(), z());
}

